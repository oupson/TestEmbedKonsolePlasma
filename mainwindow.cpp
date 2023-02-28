#include "mainwindow.h"

#include <KService>
#include <KTextEdit>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : KXmlGuiWindow(parent) {
  KService::Ptr service = KService::serviceByDesktopName("konsolepart");
  if (service) {
    std::cout << "Got service" << std::endl;
    m_part = service->createInstance<KParts::ReadOnlyPart>(0);
    if (m_part) {
      // tell the KParts::MainWindow that this is indeed
      // the main widget
      setCentralWidget(m_part->widget());

      setupGUI();

      // and integrate the part's GUI with the shell's
      //createGUI(m_part);
    } else {
		std::cerr << "no part" << std::endl;
		return; // return 1;
    }
  } else {
    std::cerr << "No service :/" << std::endl;
  }
}
