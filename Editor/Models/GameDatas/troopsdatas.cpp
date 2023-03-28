/*
    RPG Paper Maker Copyright (C) 2017-2023 Wano

    RPG Paper Maker engine is under proprietary license.
    This source code is also copyrighted.

    Use Commercial edition for commercial use of your games.
    See RPG Paper Maker EULA here:
        http://rpg-paper-maker.com/index.php/eula.
*/

#include "troopsdatas.h"
#include "rpm.h"
#include "common.h"
#include "systemtroop.h"
#include "systemmonstertroop.h"

// -------------------------------------------------------
//
//  CONSTRUCTOR / DESTRUCTOR / GET / SET
//
// -------------------------------------------------------

TroopsDatas::TroopsDatas()
{
    m_model = new QStandardItemModel;
}

TroopsDatas::~TroopsDatas()
{
    SuperListItem::deleteModel(m_model);
}

void TroopsDatas::read(QString path){
    RPM::readJSON(Common::pathCombine(path, RPM::PATH_TROOPS), *this);
}

QStandardItemModel* TroopsDatas::model() const { return m_model; }

// -------------------------------------------------------
//
//  INTERMEDIARY FUNCTIONS
//
// -------------------------------------------------------

void TroopsDatas::setDefault(QStandardItem *modelMonsters){
    SystemTroop* sysTroop;
    SystemMonsterTroop* sysMonsterTroop;
    QStandardItem* itemMonster;
    QStandardItem* itemLevel;
    QStandardItem* item;
    SuperListItem* monster;
    int id;
    int level;
    QList<QStandardItem *> row;
    QStandardItemModel* monsters;
    QString names[] = {
        RPM::translate(Translations::TROOP_1),
        RPM::translate(Translations::TROOP_2),
        RPM::translate(Translations::TROOP_3)
    };
    QVector<int> idsMonsters[] = {QVector<int>({1}), QVector<int>({1, 1}),
        QVector<int>({1})};
    QVector<int> levels[] = {QVector<int>({1}), QVector<int>({1, 1}),
        QVector<int>({5})};

    int length = (sizeof(names)/sizeof(*names));

    for (int i = 0; i < length; i++){

        // Monsters list
        monsters = new QStandardItemModel;
        for (int j = 0; j < idsMonsters[i].size(); j++){
            row = QList<QStandardItem*>();
            id = idsMonsters[i][j];
            monster = SuperListItem::getById(modelMonsters, id);
            level = levels[i][j];
            sysMonsterTroop = new SystemMonsterTroop(id, monster->name(), new
                PrimitiveValue(level));
            itemMonster = new QStandardItem;
            itemMonster->setData(
                        QVariant::fromValue(
                            reinterpret_cast<quintptr>(sysMonsterTroop)));
            itemMonster->setText(sysMonsterTroop->toString());
            itemLevel = new QStandardItem;
            itemLevel->setData(QVariant::fromValue(level));
            itemLevel->setText(QString::number(level));
            row.append(itemMonster);
            row.append(itemLevel);
            monsters->appendRow(row);
        }
        item = new QStandardItem();
        item->setText(SuperListItem::beginningText);
        monsters->appendRow(item);

        // System troop
        sysTroop = new SystemTroop(i+1, names[i], monsters);
        m_model->appendRow(sysTroop->getModelRow());
    }
}

void TroopsDatas::setDefaultTranslations()
{
    SuperListItem::setModelItemName(m_model, 0, RPM::translate(Translations::WOOLY) + "[1]");
    SuperListItem::setModelItemName(m_model, 1, RPM::translate(Translations::WOOLY) + "[1](2)");
    SuperListItem::setModelItemName(m_model, 2, RPM::translate(Translations::MUSHROOMY) + "[3]");
    SuperListItem::setModelItemName(m_model, 3, RPM::translate(Translations::MUSHROOMY) + "[3](2)");
    SuperListItem::setModelItemName(m_model, 4, RPM::translate(Translations::SLIME_BLUE) + "[5]");
    SuperListItem::setModelItemName(m_model, 5, RPM::translate(Translations::SLIME_BLUE) + "[5](2)");
    SuperListItem::setModelItemName(m_model, 6, RPM::translate(Translations::SLIME_BLACK) + "[10]");
    SuperListItem::setModelItemName(m_model, 7, RPM::translate(Translations::SLIME_BLACK) + "[10](2)");
    SuperListItem::setModelItemName(m_model, 8, RPM::translate(Translations::SLIME_BLUE) + "[10]" + RPM::translate(Translations::SLIME_BLACK) + "[10]");
    SuperListItem::setModelItemName(m_model, 9, RPM::translate(Translations::SLIME_GOLD) + "[20]");
    SuperListItem::setModelItemName(m_model, 10, RPM::translate(Translations::BAT) + "[5]");
    SuperListItem::setModelItemName(m_model, 11, RPM::translate(Translations::BAT) + "[5](2)");
    SuperListItem::setModelItemName(m_model, 12, RPM::translate(Translations::RAT) + "[3]");
    SuperListItem::setModelItemName(m_model, 13, RPM::translate(Translations::RAT) + "[3](2)");
    SuperListItem::setModelItemName(m_model, 14, RPM::translate(Translations::BAT) + "[5]" + RPM::translate(Translations::RAT) + "[5]");
    SuperListItem::setModelItemName(m_model, 15, RPM::translate(Translations::ZOMBIE) + "[10]");
    SuperListItem::setModelItemName(m_model, 16, RPM::translate(Translations::ZOMBIE) + "[10](2)");
    SuperListItem::setModelItemName(m_model, 17, RPM::translate(Translations::GOBLIN) + "[10]");
    SuperListItem::setModelItemName(m_model, 18, RPM::translate(Translations::SKELETON) + "[15]");
    SuperListItem::setModelItemName(m_model, 19, RPM::translate(Translations::SKELETON) + "[15](2)");
    SuperListItem::setModelItemName(m_model, 20, RPM::translate(Translations::SKELETON) + "[15]" + RPM::translate(Translations::GOBLIN) + "[15]");
    SuperListItem::setModelItemName(m_model, 21, RPM::translate(Translations::SPIDER) + "[18]");
    SuperListItem::setModelItemName(m_model, 22, RPM::translate(Translations::SPIDER) + "[18](2)");
    SuperListItem::setModelItemName(m_model, 23, RPM::translate(Translations::FANTOM) + "[20]");
    SuperListItem::setModelItemName(m_model, 24, RPM::translate(Translations::FANTOM) + "[20](2)");
    SuperListItem::setModelItemName(m_model, 25, RPM::translate(Translations::SKELETON) + "[20]" + RPM::translate(Translations::SPIDER) + "[20]" + RPM::translate(Translations::FANTOM) + "[20]");
    SuperListItem::setModelItemName(m_model, 26, RPM::translate(Translations::HARPY) + "[25]");
    SuperListItem::setModelItemName(m_model, 27, RPM::translate(Translations::HARPY) + "[25](2)");
    SuperListItem::setModelItemName(m_model, 28, RPM::translate(Translations::SQUID) + "[30]");
    SuperListItem::setModelItemName(m_model, 29, RPM::translate(Translations::SQUID) + "[30](2)");
    SuperListItem::setModelItemName(m_model, 30, RPM::translate(Translations::LAMIA) + "[35]");
    SuperListItem::setModelItemName(m_model, 31, RPM::translate(Translations::LAMIA) + "[35](2)");
    SuperListItem::setModelItemName(m_model, 32, RPM::translate(Translations::KNIGHT) + "[40]");
    SuperListItem::setModelItemName(m_model, 33, RPM::translate(Translations::KNIGHT) + "[40](2)");
    SuperListItem::setModelItemName(m_model, 34, RPM::translate(Translations::MIMIC) + "[50]");
    SuperListItem::setModelItemName(m_model, 35, RPM::translate(Translations::OGRE) + "[50]");
    SuperListItem::setModelItemName(m_model, 36, RPM::translate(Translations::OGRE) + "[50](2)");
    SuperListItem::setModelItemName(m_model, 37, RPM::translate(Translations::DEMON) + "[60]");
    SuperListItem::setModelItemName(m_model, 38, RPM::translate(Translations::ANGEL) + "[75]");
    SuperListItem::setModelItemName(m_model, 39, RPM::translate(Translations::ANGEL) + "[100]");
    SuperListItem::setModelItemName(m_model, 40, RPM::translate(Translations::DEMON) + "[100]");
    SuperListItem::setModelItemName(m_model, 41, RPM::translate(Translations::ANGEL) + "[50]");
    SuperListItem::setModelItemName(m_model, 42, RPM::translate(Translations::OGRE) + "[50](3)");
}

// -------------------------------------------------------
//
//  READ / WRITE
//
// -------------------------------------------------------

void TroopsDatas::read(const QJsonObject &json){

    // Clear
    SuperListItem::deleteModel(m_model, false);

    // Read
    QJsonArray jsonList = json["troops"].toArray();
    for (int i = 0; i < jsonList.size(); i++){
        QStandardItem* item = new QStandardItem;
        SystemTroop* sysTroop = new SystemTroop;
        sysTroop->read(jsonList[i].toObject());
        item->setData(QVariant::fromValue(
                          reinterpret_cast<quintptr>(sysTroop)));
        item->setFlags(item->flags() ^ (Qt::ItemIsDropEnabled));
        item->setText(sysTroop->toString());
        m_model->appendRow(item);
    }
}

// -------------------------------------------------------

void TroopsDatas::write(QJsonObject &json) const{
    QJsonArray jsonArray;
    for (int i = 0; i < m_model->invisibleRootItem()->rowCount(); i++){
        QJsonObject jsonCommon;
        SystemTroop* sysTroop = ((SystemTroop*)m_model->item(i)->data()
                                 .value<quintptr>());
        sysTroop->write(jsonCommon);
        jsonArray.append(jsonCommon);
    }
    json["troops"] = jsonArray;
}
