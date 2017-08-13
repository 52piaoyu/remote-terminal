// This application is under GNU GPLv3. Please read the COPYING.txt file for further terms and conditions of the license.
// Copyright © 2017 Matthew James
// "Remote Terminal" is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// "Remote Terminal" is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with "Remote Terminal". If not, see http://www.gnu.org/licenses/.

#ifndef FRMPROFILEMANAGER_H
#define FRMPROFILEMANAGER_H

#include "ui_frmprofilemanager.h"
#include "profilemanager.h"

namespace Ui
{
    class frmProfileManager;
}

class frmProfileManager : public QWidget
{
    Q_OBJECT

public:
    explicit frmProfileManager(ProfileManager&, QWidget *parent = 0);
    void EnableProfileFields();
    void DisableProfileFields();
    void LoadProfile(int);
    bool IsDefaultProfileSelected();

public slots:
    void AddNewProfile();
    void DeleteProfile();
    void SaveProfile();
    void LoadProfiles();
    void CheckShowPassword();
    void OnProfileItemClick(QListWidgetItem*);
    void OnProfileItemChange(int);

private:
    ProfileManager *profileManager;
    QVector<Profile*> storedProfiles;
    Ui::frmProfileManager *ui;
    int selectedProfileIndex;
};

#endif // FRMPROFILEMANAGER_H
