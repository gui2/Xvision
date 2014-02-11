#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QtGui/QApplication>
#include <QFileDialog>
#include <QDialog>
#include "ui_ConfigDialog.h"

namespace tld
{
class Settings;
}

/**
 * Creates a dialog and provides the configured parameters
 * @param argc number of command line arguments
 * @param argv command line arguments
 * @param settings all parameters are stored in this object
 * @return true if everything went right, false if not
 */
bool getSettingsFromConfigDialog(int argc, char *argv[],
                                 tld::Settings *settings);

/**
 * Qt-Dialog to configure the program
 */
class ConfigDialog: public QDialog
{
    Q_OBJECT
public:
    /**
     * Creates a dialog
     * @param settings all parameters are stored in this object
     * @param correctClosed true if everything went right, false if not
     */
    ConfigDialog() {}
    ConfigDialog(tld::Settings *settings, bool *correctClosed, QWidget *parent = 0);
    ~ConfigDialog();

protected:
    void changeEvent(QEvent *e);

private:
    tld::Settings *m_settings;
    bool *m_correctClosed;
    Ui_ConfigDialog *ui;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_pushButton_printTiming_clicked();
    void on_pushButton_outputDir_clicked();
    void on_pushButton_printResults_clicked();
    void on_pushButton_modelPath_clicked();
    void on_pushButton_imagePath_clicked();
    void on_comboBox_method_activated(QString element);
};

#endif // CONFIGDIALOG_H
