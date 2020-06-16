#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QString>
#include <QObject>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QDialog>
#include <QFileDialog>
#include <QDockWidget>
#include <QTreeWidget>
#include <QMessageBox>
#include <QActionGroup>
#include <QProgressDialog>
#include <QVBoxLayout>

#include "QsfMainWindow.h"
#include "uiOffice2016.h"


uiOffice2016::uiOffice2016()
{
	m_menuImg = "��ͼ";
	m_menuTable = "���";

	//* tMW = new QtbMainWindow();
	QsrRibbonTitleBar* tBar = titleBar();
	tBar->setTitle(QObject::tr("Ribbon 2016 OFFICE ��� WORD ��ʽ"));
	QAction* tActSave = new QAction(QIcon("../userData/img/Save.png"), "Save");
	QAction* tActUndo = new QAction(QIcon("../userData/img/Undo.png"), "Undo");
	QAction* tActRedo = new QAction(QIcon("../userData/img/Redo.png"), "Redo");
	tBar->addQuickAction(tActSave);
	tBar->addQuickAction(tActUndo);
	tBar->addQuickAction(tActRedo);
	QAction* tActClose = new QAction(QIcon("../userData/img/TitleCloseButton.png"), "Close");
	QAction* tActMax = new QAction(QIcon("../userData/img/TitleMaxButton.png"), "Max");
	QAction* tActSkin = new QAction(QIcon("../userData/img/skin.png"), "Skin");
	tBar->addSysAction(tActClose);
	QObject::connect(tActClose, SIGNAL(triggered()), this, SLOT(close()));
	tBar->addSysAction(tActMax);
	tBar->addSysAction(tActSkin);
	QObject::connect(tActSkin, SIGNAL(triggered()), this, SLOT(onSkin()));

	QIcon tIcon = QIcon("../userData/img/brush.png");

	QtbMenuBar* tMenuBar = menuBar();

	tMenuBar->setExtentBtnIcon(QIcon("../userData/img/iconExtent.png"), QIcon("../userData/img/iconHide.png"));

	RibbonToolButton* tempBtn = new RibbonToolButton("�ļ�");
	tempBtn->setAlignment(Qt::AlignCenter);
	tempBtn->setMinimumWidth(54);
	tempBtn->setMinimumHeight(32);
	tempBtn->setStyleSheet("color:white;");
	tMenuBar->addAction(tempBtn, 0);
	
	tMenuBar->addMenu("��ʼ");
	QtbGroupWidget* tGW = tMenuBar->addGroup("��ʼ", "������");
	if (tGW)
	{
		ribbonAction* tAct = new RibbonToolButton(QIcon("../userData/img/ruanJian.png"), "ճ��");
		((RibbonToolButton*)tAct)->setTxtVisible(false);
		((RibbonToolButton*)tAct)->setAlignment(Qt::AlignCenter);

		((RibbonToolButton*)tAct)->setIconSize(QSize(48, 48));
		tGW->addAction(tAct, 0, 0, 3, 1);
		tAct = new RibbonToolButton(QIcon("../userData/img/cut.png"), "����");
		tGW->addAction(tAct, 0, 1, 1, 1);
		tAct = new RibbonToolButton(QIcon("../userData/img/copy.png"), "����");
		tGW->addAction(tAct, 1, 1, 1, 1);
		tAct = new RibbonToolButton(QIcon("../userData/img/brush.png"), "��ʽˢ");
		tGW->addAction(tAct, 2, 1, 1, 1);
	}
	tGW = tMenuBar->addGroup("��ʼ", "����");
	if (tGW)
	{
		int tRow = 0, tCol = 0;
		ribbonAction* tAct = new QComboBox();
		((QComboBox*)tAct)->addItem("΢���ź�");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new QComboBox();
		((QComboBox*)tAct)->addItem("���");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/zoomin.png"), "�Ŵ�");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/zoomout.png"), "��С");
		tGW->addAction(tAct, tRow, tCol++);

		tRow = 1;
		tCol = 0;
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "�Ӵ�");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "б��");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "�»���");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "ɾ����");
		tGW->addAction(tAct, tRow, tCol++);
	}
	tGW = tMenuBar->addGroup("��ʼ", "����");
	if (tGW)
	{
		int tRow = 0, tCol = 0;
		ribbonAction* tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "���");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "�б�");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����");
		tGW->addAction(tAct, tRow, tCol++);

		tRow = 1;
		tCol = 0;
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "�����");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����");
		tGW->addAction(tAct, tRow, tCol++);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "�Ҷ���");
		tGW->addAction(tAct, tRow, tCol++);
	}
	tGW = tMenuBar->addGroup("��ʼ", "��ʽ");
	if (tGW)
	{
		ribbonAction* tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����");
		tGW->addAction(tAct, 0, 0);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����1");
		tGW->addAction(tAct, 0, 1);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����2");
		tGW->addAction(tAct, 0, 2);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����3");
		tGW->addAction(tAct, 0, 3);
	}
	tGW = tMenuBar->addGroup("��ʼ", "�༭");
	if (tGW)
	{
		ribbonAction* tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����");
		tGW->addAction(tAct, 0, 0);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "�滻");
		tGW->addAction(tAct, 1, 0);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "ѡ��");
		tGW->addAction(tAct, 2, 0);
	}

	tMenuBar->addMenu("����");
	tGW = tMenuBar->addGroup("����", "������");
	if (tGW)
	{
		ribbonAction* tAct = new RibbonToolButton("ճ��");
		tGW->addAction(tAct, 0, 0, 3, 1);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����");
		tGW->addAction(tAct, 0, 1, 1, 1);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "����");
		tGW->addAction(tAct, 1, 1, 1, 1);
		tAct = new RibbonToolButton(QIcon("../userData/img/down.png"), "ճ��");
		tGW->addAction(tAct, 2, 1, 1, 1);
	}

	QString strMenu = "���";
	tMenuBar->addMenu(strMenu);
	tGW = tMenuBar->addGroup(strMenu, "ҳ��");
	if (tGW)
	{
		ribbonAction* tAct = new RibbonToolButton(tIcon,"����");
		tGW->addAction(tAct, 0, 0);
		tAct = new RibbonToolButton(tIcon,"�հ�ҳ");
		tGW->addAction(tAct, 1, 0);
		tAct = new RibbonToolButton(tIcon,"��ҳ");
		tGW->addAction(tAct, 2, 0);
	}

	tMenuBar->addMenu("����");
	tMenuBar->addMenu("����");
	tMenuBar->addMenu("�ʼ�");
	tMenuBar->addMenu("����");
	tMenuBar->addMenu("������");

    //connect()

	tMenuBar->addMenu(m_menuImg);
	tMenuBar->setMenuVisible(m_menuImg, false);

	tMenuBar->addMenu(m_menuTable);
	tMenuBar->setMenuVisible(m_menuTable, false);

	int tIndex = 0;
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::LeftDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::LeftDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::LeftDockWidgetArea);

	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::RightDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::RightDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::RightDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::RightDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::RightDockWidgetArea);

	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::BottomDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::BottomDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::BottomDockWidgetArea);
	createDockWidget(QString("DOCK����%1").arg(tIndex++), QString("DOCK_%1").arg(tIndex++), Qt::BottomDockWidgetArea);

	createWorkWidget("�ĵ�1", "WORK_WIDGET_1");
	createWorkWidget("�ĵ�2", "WORK_WIDGET_2");
	createWorkWidget("�ĵ�3", "WORK_WIDGET_3");

}


uiOffice2016::~uiOffice2016()
{
}

void uiOffice2016::onImgClicked()
{
    QtbMenuBar* tMenuBar = menuBar();
    tMenuBar->setMenuVisible(m_menuImg, true);
}




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////



uiTEST_MainWindow::uiTEST_MainWindow()
{
    m_widget = new QWidget();
    m_generateWid = new QWidget();
    m_traineWid = new QWidget();
    doLayout(false);

    initTitleBar();
    initMenuBar();
    initWorkTabWidget();

    //PyEngine::init();
    //vsRecource::createRecource();
}

uiTEST_MainWindow::~uiTEST_MainWindow()
{
    //PyEngine::finalize();
}

/*����ĳ�ʼ���У�������Action��button��û���ͷţ���Ϊ���Ժ���ڹ������С�
�Ժ�Ҫ�ڹ������д������ͷ�
*/
void uiTEST_MainWindow::initTitleBar()
{
    QsrRibbonTitleBar* tBar = titleBar();
    tBar->setTitle(QObject::tr("�˹����ܵ�����߷ֱ������ V1.0"));
    // 	QAction* tActSave = new QAction(QIcon("../userData/img/Save.png"), "ϵͳ����");
    // 	QAction* tActUndo = new QAction(QIcon("../userData/img/Save.png"), "��������");
    // 	QAction* tActRedo = new QAction(QIcon("../userData/img/Save.png"), "�������");
    //     // �ȼӵ������
    // 	tBar->addQuickAction(tActSave);
    // 	tBar->addQuickAction(tActUndo);
    // 	tBar->addQuickAction(tActRedo);
    QAction* tActClose = new QAction(QIcon("../userData/img/TitleCloseButton.png"), "Close");
    QAction* tActMax = new QAction(QIcon("../userData/img/TitleMaxButton.png"), "Max");
    QAction* tActMin = new QAction(QIcon("../userData/img/TitleMinButton.png"), "Min");
    QAction* tActSkin = new QAction(QIcon("../userData/img/skin.png"), "Skin");
    // �ȼӵ����ұ�
    tBar->addSysAction(tActClose);
    QObject::connect(tActClose, SIGNAL(triggered()), this, SLOT(close()));
    tBar->addSysAction(tActMax);
    QObject::connect(tActMax, SIGNAL(triggered()), this, SLOT(showMaximized()));
    tBar->addSysAction(tActMin);
    QObject::connect(tActMin, SIGNAL(triggered()), this, SLOT(showMinimized()));
    tBar->addSysAction(tActSkin);
    QObject::connect(tActSkin, SIGNAL(triggered()), this, SLOT(onSkin()));
}

void uiTEST_MainWindow::initMenuBar()
{
    QIcon tIconBig; 
    QIcon tIconSmall; 

    QtbMenuBar* tMenuBar = menuBar();
    // SgfParamManager::GetInstance()->addParam(APP_MENU_BAR, tMenuBar); // ȫ�ֲ���������
    tMenuBar->setExtentBtnIcon(QIcon("../userData/img/iconExtent.png"), QIcon("../userData/img/iconHide.png"));

    QString strMenu = " ���������߷ֱ���  ";
    tMenuBar->addMenu(strMenu);

    QtbGroupWidget* tGW = NULL;

    tGW = tMenuBar->addGroup(strMenu, "ģ��ѵ��");
    if (tGW)
    {
        int tCol = 0;
        tIconBig = QIcon("../userData/img/menu_model_train.png");
        ribbonAction* tAct = new RibbonToolButtonBig(tIconBig, "    ��������    ");
        tGW->addAction(tAct, 0, tCol++, 3, 1);
        connect(tAct, SIGNAL(triggered()), this, SLOT(on_generate_toggled()));

        tIconBig = QIcon("../userData/img/menu_model_train.png");
        tAct = new RibbonToolButtonBig(tIconBig, "    ѵ��ģ��    ");
        tGW->addAction(tAct, 0, tCol++, 3, 1);
        //connect(tAct, SIGNAL(triggered()), this, SLOT(onTrainModel()));
        connect(tAct, SIGNAL(triggered()), this, SLOT(on_train_toggled()));
    }

    tGW = tMenuBar->addGroup(strMenu, "ģ��Ӧ��");
    if (tGW)
    {
        int tCol = 0;
        ribbonAction* tAct = NULL;
        tIconBig = QIcon("../userData/img/menu_predict_model.png");
        tAct = new RibbonToolButtonBig(tIconBig, "    ѡ��ģ��    ");
        tGW->addAction(tAct, 0, tCol++, 3, 1);
        connect(tAct, SIGNAL(triggered()), m_widget, SLOT(on_btnOpenModel_toggled()));
        connect(tAct, SIGNAL(triggered()), this, SLOT(on_predict_toggled()));

        tIconBig = QIcon("../userData/img/menu_predict_data.png");
        tAct = new RibbonToolButtonBig(tIconBig, " ѡ���Ԥ������ ");
        tGW->addAction(tAct, 0, tCol++, 3, 1);
        connect(tAct, SIGNAL(triggered()), m_widget, SLOT(on_btnOpenSEGY_toggled()));
        connect(tAct, SIGNAL(triggered()), this, SLOT(on_predict_toggled()));

        tIconBig = QIcon("../userData/img/menu_predict_data.png");
        tAct = new RibbonToolButtonBig(tIconBig, " ѡ���λ ");
        tGW->addAction(tAct, 0, tCol++, 3, 1);
        connect(tAct, SIGNAL(triggered()), m_widget, SLOT(on_btnOpenHor_toggled()));
        connect(tAct, SIGNAL(triggered()), this, SLOT(on_predict_toggled()));


        tIconBig = QIcon("../userData/img/menu_predict.png");
        tAct = new RibbonToolButtonBig(tIconBig, "    Ԥ��Ӧ��    ");
        tGW->addAction(tAct, 0, tCol++, 3, 1);
        connect(tAct, SIGNAL(triggered()), m_widget, SLOT(on_btnRun_toggled()));
        connect(tAct, SIGNAL(triggered()), this, SLOT(on_predict_toggled()));
    }

    tGW = tMenuBar->addGroup(strMenu, "  ����  ");
    if (tGW)
    {
        int tCol = 0;
        tIconBig = QIcon("../userData/img/menu_show_section1.png");
        ribbonAction* tAct = new RibbonToolButtonBig(tIconBig, "  �½����ݿ�  ");
        //tGW->addAction(tAct, 0, tCol++, 2, 1);
        connect(tAct, SIGNAL(triggered()), this, SLOT(onCreateDB()));

        tIconBig = QIcon("../userData/img/menu_show_section2.png");
        tAct = new RibbonToolButtonBig(tIconBig, "   ����   ");
        tGW->addAction(tAct, 0, tCol++, 2, 1);
        connect(tAct, SIGNAL(triggered()), this, SLOT(onAbout()));

        tIconBig = QIcon("zhifubao.png");
        tAct = new RibbonToolButtonBig(tIconBig, "   ֧��   ");
        tGW->addAction(tAct, 0, tCol++, 2, 1);
        connect(tAct, SIGNAL(triggered()), this, SLOT(onSupport()));
    }
}




void uiTEST_MainWindow::initDockWidget()
{
    QIcon tIcon0 = QIcon("../userData/img/icon/tree_item_top.png");
    QIcon tIcon1 = QIcon("../userData/img/icon/tree_item.png");

    QDockWidget* tDock = NULL;
    tDock = createDockWidget("Project", DOCK_PROJCET, Qt::RightDockWidgetArea); // ����
    QTreeWidget* tTree = new QTreeWidget();
    //SgfParamManager::GetInstance()->addParam(TREE_DATA, tTree);
    tTree->setHeaderLabel("");
    QTreeWidgetItem* tItem = new QTreeWidgetItem(); tItem->setText(0, "SEGY"); tItem->setIcon(0, tIcon0);
    tTree->addTopLevelItem(tItem); tItem->setData(0, 3, TREE_DATA_SEGY);
    QTreeWidgetItem* tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "����������.segy"); tItem1->setIcon(0, tIcon1); tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "���������.segy"); tItem1->setIcon(0, tIcon1); tItem->addChild(tItem1);
    tItem->setExpanded(true);

    tItem = new QTreeWidgetItem(); tItem->setText(0, "��λ"); tItem->setIcon(0, tIcon0);
    tTree->addTopLevelItem(tItem); tItem->setData(0, 3, TREE_DATA_HOR);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "T74.dat"); tItem1->setIcon(0, tIcon1); tItem->addChild(tItem1);
    tItem->setExpanded(true);

    tItem = new QTreeWidgetItem(); tItem->setText(0, "��ǩ��"); tItem->setIcon(0, tIcon0);
    tTree->addTopLevelItem(tItem); tItem->setData(0, 3, TREE_DATA_SAMPLEWELL);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-1"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-2"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-3"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-4"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-5"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-6"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-7"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-8"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem1 = new QTreeWidgetItem(); tItem1->setText(0, "JH-9"); tItem1->setIcon(0, tIcon1);  tItem->addChild(tItem1);
    tItem->setExpanded(true);

    tDock->setWidget(tTree);

}

void uiTEST_MainWindow::initWorkTabWidget()
{
    m_workWindow->workSpace()->setTabsClosable(true);
    m_workWindow->workSpace()->addTab(m_generateWid, "   ��������   ");
    m_workWindow->workSpace()->addTab(m_traineWid, "   ѵ��ģ��   ");
    m_workWindow->workSpace()->addTab(m_widget, "   Ԥ��Ӧ��   ");
}

/*@brief �رչ�������ǩ*/
void uiTEST_MainWindow::onCloseWorkTab(int tabIndex)
{
    if (tabIndex >= 4)
    {
        // ��Tabҳ���Ƴ�
        m_workWindow->workSpace()->removeTab(tabIndex);
    }
}



void uiTEST_MainWindow::onAbout()
{
    QString txt = "���ڵ���������߷ֱ������(V1.0)\n";
    txt += "                2019��12��\n";
    txt += "         ��������ñ���������а���\n";
    txt += "            ��֧���ҵĿ�����лл\n";

    QMessageBox::about(this, "����", txt);
}

void uiTEST_MainWindow::onSupport()
{
    QDialog * tw = new QDialog(this);
    tw->setWindowTitle("֧������");
    QPalette pal = tw->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap("zhifubao.png")));
    tw->setPalette(pal);
    tw->resize(281, 391);
    tw->exec();

}

void uiTEST_MainWindow::on_generate_toggled()
{
    m_workWindow->workSpace()->setCurrentWidget(m_generateWid);
}

void uiTEST_MainWindow::on_train_toggled()
{
    m_workWindow->workSpace()->setCurrentWidget(m_traineWid);
}

void uiTEST_MainWindow::on_predict_toggled()
{
    m_workWindow->workSpace()->setCurrentWidget(m_widget);
}

void uiTEST_MainWindow::closeEvent(QCloseEvent * event)
{
    doLayout(true);
}

void uiTEST_MainWindow::doLayout(bool isSave)
{
    QString layoutFile = "msqcMain.layout.dat";
    if (isSave)
    {
        QFile file(layoutFile);
        if (!file.open(QFile::WriteOnly))
        {
            QString msg = tr("Failed to open %1\n%2")
                .arg(layoutFile)
                .arg(file.errorString());
            QMessageBox::warning(this, tr("Error"), msg);
            return;
        }

        QByteArray geo_data = saveGeometry();
        QByteArray layout_data = m_workWindow->saveState();

        bool ok = file.putChar((uchar)geo_data.size());
        if (ok)
        {
            ok = file.write(geo_data) == geo_data.size();
        }
        if (ok)
        {
            ok = file.write(layout_data) == layout_data.size();
        }
        if (!ok)
        {
            QString msg = tr("Error writing to %1\n%2")
                .arg(layoutFile)
                .arg(file.errorString());
            QMessageBox::warning(this, tr("Error"), msg);
            return;
        }
    }
    else
    {
        if (layoutFile.isEmpty())
            return;
        QFile file(layoutFile);
        if (!file.open(QFile::ReadOnly))
        {
            QString msg = tr("Failed to open %1\n%2")
                .arg(layoutFile)
                .arg(file.errorString());
            QMessageBox::warning(this, tr("Error"), msg);
            return;
        }

        uchar geo_size;
        QByteArray geo_data;
        QByteArray layout_data;

        bool ok = file.getChar((char*)&geo_size);
        if (ok)
        {
            geo_data = file.read(geo_size);
            ok = geo_data.size() == geo_size;
        }
        if (ok)
        {
            layout_data = file.readAll();
            ok = layout_data.size() > 0;
        }

        if (ok)
        {
            ok = restoreGeometry(geo_data);
        }
        if (ok)
        {
            ok = this->m_workWindow->restoreState(layout_data);
        }
        if (!ok)
        {
            QString msg = tr("Error reading %1")
                .arg(layoutFile);
            QMessageBox::warning(this, tr("Error"), msg);
            return;
        }
    }

}


