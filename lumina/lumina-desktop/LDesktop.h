//===========================================
//  Lumina-DE source code
//  Copyright (c) 2012, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef _LUMINA_DESKTOP_LDESKTOP_H
#define _LUMINA_DESKTOP_LDESKTOP_H

#include <QCoreApplication>


#include <QSettings>
#include <QFile>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <QFileSystemWatcher>
#include <QLabel>
#include <QWidgetAction>


#include <LuminaXDG.h>

#include "LPanel.h"
#include "Globals.h"
#include "LSession.h"
#include "desktop-plugins/LDPlugin.h"
#include "desktop-plugins/NewDP.h"

class LDesktop : public QObject{
	Q_OBJECT
public:
	LDesktop(int deskNum=0);
	~LDesktop();
	
public slots:
	void SystemLogout(){ LSession::systemWindow(); }
	void SystemTerminal();
	
private:
	QSettings *settings;
	QTimer *bgtimer;
	QDesktopWidget *desktop;
	QString DPREFIX;
	int desktopnumber;
	int xoffset;
	bool defaultdesktop;
	QList<LPanel*> PANELS;
	QWidget *bgWindow;
	QMenu *deskMenu;
	AppMenu *appmenu;
	QLabel *workspacelabel;
	QWidgetAction *wkspaceact;
	QList<LDPlugin*> PLUGINS;
	QFileSystemWatcher *watcher;
	QString CBG; //current background
	
private slots:
	void SettingsChanged();
	void UpdateMenu(bool fast = false);
	void ShowMenu(){
	  UpdateMenu(true); //run the fast version
	  deskMenu->popup(QCursor::pos());
	}
	
	void UpdateDesktop();
	
	void UpdatePanels();

	void UpdateBackground();

};
#endif
