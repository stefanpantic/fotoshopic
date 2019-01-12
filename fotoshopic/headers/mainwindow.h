#pragma once

#include <vector>

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QFormLayout>
#include <QDialog>
#include <QLineEdit>
#include <QList>
#include <QDialogButtonBox>
#include <QButtonGroup>
#include <QRadioButton>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "image.h"
#include "image_params.h"
#include "section.h"
#include "utils.h"
#include "utils/image_history.hpp"
//#include "edit_operations.h"

//template <typename T>
//using qstring_map = std::unordered_map<QString, T>;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
	Q_OBJECT

	/* Public member functions */
	public:
		explicit MainWindow(QWidget *parent = nullptr);
		~MainWindow();

	/* Private slots */
	private slots:
		void on_action_ZoomIn_triggered();
		void on_action_ZoomOut_triggered();
		void on_btRGB_triggered();
		void on_btGray_triggered();
		void on_action_Mirror_triggered();
		void on_action_Open_triggered();
		void on_action_Save_triggered();
		void on_action_SaveAs_triggered();
		void on_action_Delete_triggered();
		void on_action_Exit_triggered();
		void on_action_Resize_triggered();
		void on_action_Rotate_left_triggered();
		void on_action_Rotate_right_triggered();
        void on_action_Undo_triggered();
        void on_action_Redo_triggered();
		void on_action_Crop_triggered();

	/* Private member functions */
	private:
		void show_image();
		void save_image(const std::string& fileName);
		void slider_operation(QSlider *slider, const QString &name, int value = 50);
		void create_section(const QString &name, const std::vector<std::pair<QString, int>> &contents);
		void sync_sections();

	/* Private variables */
	private:
		Ui::MainWindow *ui;
		QLabel* m_lb_image;
		bool m_has_image;
		rs::utils::image_history m_history;
		std::vector<Section*> m_sections;
		qstring_map<QSlider*> m_sliders;
		std::string m_filename;
};

