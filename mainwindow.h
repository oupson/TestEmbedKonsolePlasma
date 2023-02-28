#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <KXmlGuiWindow>
#include <KParts/ReadWritePart>

class KTextEdit;
 
class MainWindow : public KXmlGuiWindow
{
public:
    explicit MainWindow(QWidget *parent = nullptr);
 
private:
    KTextEdit *textArea;
	KParts::ReadOnlyPart *m_part;
};
 
#endif // MAINWINDOW_H
