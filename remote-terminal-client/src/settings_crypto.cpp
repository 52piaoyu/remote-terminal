// This application is under GNU GPLv3. Please read the COPYING.txt file for further terms and conditions of the license.
// Copyright © 2017 Matthew James
// "Remote Terminal" is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// "Remote Terminal" is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with "Remote Terminal". If not, see http://www.gnu.org/licenses/.

#include "settings_crypto.h"

QString SettingsCrypto::GetUniqueSystemHash()
{
    QString uniqueHash = qgetenv("USER") + "_" + QDir::homePath() + "_" +
                         QSysInfo::currentCpuArchitecture() + "_" +
                         QSysInfo::productType() + "_" +
                         QSysInfo::kernelType();

    return QString(QCryptographicHash::hash(uniqueHash.toUtf8(),QCryptographicHash::Sha512).toHex());
}
