/*
    RPG Paper Maker Copyright (C) 2017-2020 Wano

    RPG Paper Maker engine is under proprietary license.
    This source code is also copyrighted.

    Use Commercial edition for commercial use of your games.
    See RPG Paper Maker EULA here:
        http://rpg-paper-maker.com/index.php/eula.
*/

#ifndef DIALOGSCRIPTS_H
#define DIALOGSCRIPTS_H

#include <QDialog>
#include <QModelIndex>
#include "widgetcodelinenumberarea.h"
#include "codesyntaxhighlighter.h"

// -------------------------------------------------------
//
//  CLASS DialogScripts
//
//  Dialog for system and plugins scripts management.
//
// -------------------------------------------------------

namespace Ui {
class DialogScripts;
}

class DialogScripts : public QDialog
{
    Q_OBJECT

public:
    explicit DialogScripts(QWidget *parent = nullptr);
    ~DialogScripts();

    void initialize();

private:
    Ui::DialogScripts *ui;
    WidgetCodeLineNumberArea *m_widgetLineNumber;
    CodeSyntaxHighlighter *m_highlighterSystem;
    WidgetCodeLineNumberArea *m_widgetLineNumberPlugin;
    CodeSyntaxHighlighter *m_highlighterPlugin;

public slots:
    void on_scriptSystemSelected(QModelIndex index, QModelIndex);
    void on_scriptPluginSelected(QModelIndex index, QModelIndex);
};

#endif // DIALOGSCRIPTS_H
