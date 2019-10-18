#include "StdAfx.h"
#include "Common.h"
#include "IniFile.h"
Common::Common(void)
{
}

Common::~Common(void)
{
}

void Common::Split(CString source, CStringArray& dest, CString division)
{
    dest.RemoveAll();
    int pos = 0;
    int pre_pos = 0;
    while( -1 != pos ){
        pre_pos = pos;
        pos = source.Find(division,(pos+1));
        dest.Add(source.Mid(pre_pos,(pos-pre_pos)));
    }
}

void Common::ReadUser()
{
	TCHAR buffer[1280]={0};
	CStringArray dest;

	
	CeGetPrivateProfileSectionNames(buffer, 1280, _T("\\HardDisk\\Setec\\Config\\User.ini"),dest);

	CString userName;
	int i;
	for(i=0;i<dest.GetSize();i++)
	{
		userName = dest.GetAt(i);
		CString buff;
		struct user user1;
		user1.name = userName;
		CeGetPrivateProfileString(userName, _T("Passwrd"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\User.ini"));
		user1.passwrd =buff; 

		user1.levle =CeGetPrivateProfileInt(userName, _T("level"),  
									1, _T("\\HardDisk\\Setec\\Config\\User.ini"));
		m_user.Add(user1);
	}

}

void Common::DeleteUser(CString user)
{
	CString csTemp;
	
	while (!CeWritePrivateProfileString(user, NULL, 
		NULL, _T("\\HardDisk\\Setec\\Config\\User.ini")));
		



}
void Common::WriteUser()
{

	CString csTemp;
	int i;
	
	for(i=0;i<m_user.GetSize();i++)
	{
		while (!CeWritePrivateProfileString(m_user.GetAt(i).name, _T("Passwrd"), 
			m_user.GetAt(i).passwrd, _T("\\HardDisk\\Setec\\Config\\User.ini")));
		csTemp.Format(_T("%d"), m_user.GetAt(i).levle);
		while (!CeWritePrivateProfileString(m_user.GetAt(i).name, _T("level"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\User.ini")));


	}
}

void Common::ReadModuleConfig()
{
		
	 CString buff;
	CeGetPrivateProfileString(_T("syspram-0-0"), _T("DstVel"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));
	m_syspara[0].DstVel = _wtof(buff);
	
	CeGetPrivateProfileString(_T("syspram-0-0"), _T("StartVel"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));
	m_syspara[0].StartVel = _wtof(buff);

	CeGetPrivateProfileString(_T("syspram-0-0"), _T("Acc"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));
	m_syspara[0].Acc = _wtof(buff);

	CeGetPrivateProfileString(_T("syspram-0-1"), _T("DstVel"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));
	m_syspara[1].DstVel = _wtof(buff);
	
	CeGetPrivateProfileString(_T("syspram-0-1"), _T("StartVel"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));
	m_syspara[1].StartVel = _wtof(buff);

	CeGetPrivateProfileString(_T("syspram-0-1"), _T("Acc"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));
	m_syspara[1].Acc = _wtof(buff);


	m_userpara.Dalay1 = CeGetPrivateProfileInt(_T("userparam"), _T("Dalay1"),  
									1, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));

	m_userpara.Dalay2 = CeGetPrivateProfileInt(_T("userparam"), _T("Dalay2"),  
									1, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));

	m_userpara.Dalay3 = CeGetPrivateProfileInt(_T("userparam"), _T("Dalay3"),  
									1, _T("\\HardDisk\\Setec\\Config\\Parameters.ini"));

	
	/*m_MaxVoltage = (double)CeGetPrivateProfileInt(_T("ModuleParameters"), _T("SetHighestVol"),  
									450, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));
	 m_MinVoltage = (double)CeGetPrivateProfileInt(_T("ModuleParameters"), _T("SetMinimumVol"),  
									200, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));
	 m_MaxCurrent = (double)CeGetPrivateProfileInt(_T("ModuleParameters"), _T("SetMaxCur"),  
									20, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));
	 m_ModulesNo = CeGetPrivateProfileInt(_T("ModuleParameters"), _T("ModulesNum"),  
									1, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));
	 flagdlg = (bool)CeGetPrivateProfileInt(_T("ModuleParameters"), _T("SwipeCardPortable"),  
									1, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));

	 m_MAX_GUN = CeGetPrivateProfileInt(_T("ModuleParameters"), _T("枪数总和"),  
									1, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));

	 m_ocpp_enable = (bool)CeGetPrivateProfileInt(_T("ModuleParameters"), _T("AgreementSelect"),  
									0, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));
	 CString buff;
	 CeGetPrivateProfileString(_T("ModuleParameters"), _T("电压系数"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));
	 m_voltage_coef = _wtof(buff);

	 CeGetPrivateProfileString(_T("ModuleParameters"), _T("电流系数"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini"));
	 m_current_coef = _wtof(buff);

*/
/*	 int nRet = 0;
	CString csData = L"";
	CString csFile = L"\\HardDisk\\Setec\\Config\\ModuleConfig.ini";

	nRet = CeGetPrivateProfileString(L"Coefficient", L"VolK", L"0.0432193933787172", csData.GetBuffer(100), 100, csFile);
	csData.ReleaseBuffer();
	m_VoltageK = _wtof(csData);

	nRet = CeGetPrivateProfileString(L"Coefficient", L"VolB", L"0", csData.GetBuffer(100), 100, csFile);
	csData.ReleaseBuffer();
	m_VoltageB = _wtof(csData);

	nRet = CeGetPrivateProfileString(L"Coefficient", L"CurK", L"0.0227874", csData.GetBuffer(100), 100, csFile);
	csData.ReleaseBuffer();
	m_CurrentK = _wtof(csData);

	nRet = CeGetPrivateProfileString(L"Coefficient", L"CurB", L"1.8728854", csData.GetBuffer(100), 100, csFile);
	csData.ReleaseBuffer();
	m_CurrentB = _wtof(csData);*/

}

void Common::WriteModuleConfig()const
{
	CString csTemp;

	csTemp.Format(_T("%0.8f"), m_syspara[0].DstVel);
	while (!CeWritePrivateProfileString(_T("syspram-0-0"), _T("DstVel"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));

	csTemp.Format(_T("%0.8f"), m_syspara[0].StartVel);
	while (!CeWritePrivateProfileString(_T("syspram-0-0"), _T("StartVel"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));

	csTemp.Format(_T("%0.8f"), m_syspara[0].Acc);
	while (!CeWritePrivateProfileString(_T("syspram-0-0"), _T("Acc"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));

	csTemp.Format(_T("%0.8f"), m_syspara[1].DstVel);
	while (!CeWritePrivateProfileString(_T("syspram-0-1"), _T("DstVel"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));

	csTemp.Format(_T("%0.8f"), m_syspara[1].StartVel);
	while (!CeWritePrivateProfileString(_T("syspram-0-1"), _T("StartVel"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));

	csTemp.Format(_T("%0.8f"), m_syspara[1].Acc);
	while (!CeWritePrivateProfileString(_T("syspram-0-1"), _T("Acc"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));
									
	csTemp.Format(_T("%d"), (int)m_userpara.Dalay1);
	while (!CeWritePrivateProfileString(_T("userparam"), _T("Dalay1"),  
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));

	csTemp.Format(_T("%d"), (int)m_userpara.Dalay2);
	while (!CeWritePrivateProfileString(_T("userparam"), _T("Dalay2"),  
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));
	
	csTemp.Format(_T("%d"), (int)m_userpara.Dalay3);
	while (!CeWritePrivateProfileString(_T("userparam"), _T("Dalay3"),  
									csTemp, _T("\\HardDisk\\Setec\\Config\\Parameters.ini")));


	
	/*CString csTemp;
//保存配置信息
	
	csTemp.Format(_T("%d"), (int)m_MaxVoltage);
	while (!CeWritePrivateProfileString(_T("ModuleParameters"), _T("SetHighestVol"),  
									csTemp, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini")))
		;

	csTemp.Format(_T("%d"), (int)m_MinVoltage);
	while (!CeWritePrivateProfileString(_T("ModuleParameters"), _T("SetMinimumVol"),  
									csTemp, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini")))
		;

	csTemp.Format(_T("%d"), (int)m_MaxCurrent);
	while (!CeWritePrivateProfileString(_T("ModuleParameters"), _T("SetMaxCur"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini")))
		;

	csTemp.Format(_T("%d"), m_ModulesNo);
	while (!CeWritePrivateProfileString(_T("ModuleParameters"), _T("ModulesNum"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini")))
		;

	
	csTemp.Format(_T("%d"), flagdlg);
	while (!CeWritePrivateProfileString(_T("ModuleParameters"), _T("SwipeCardPortable"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini")))
		;
	csTemp.Format(_T("%0.2f"), m_voltage_coef);
	while (!CeWritePrivateProfileString(_T("ModuleParameters"), _T("电压系数"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini")))
		;
	csTemp.Format(_T("%0.2f"), m_current_coef);
	while (!CeWritePrivateProfileString(_T("ModuleParameters"), _T("电流系数"), 
									csTemp, _T("\\HardDisk\\Setec\\Config\\ModuleConfig.ini")))
		;
		*/
}

bool Common::VerifyUser(CString user,CString pass)
{

	 CString buff;
	 CeGetPrivateProfileString(user, _T("Passwrd"), L"1",buff.GetBuffer(30), 
									30, _T("\\HardDisk\\Setec\\Config\\User.ini"));
	
	 if(buff == pass)
	 {
		return true;
	 }else
	 {
		return false;
	 }
	



}