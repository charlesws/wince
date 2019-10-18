#pragma once
using namespace std;
struct user{
	CString name ;
	CString passwrd;
	int levle;
};
struct syspram{
	double DstVel;
	double StartVel;
	double Acc;
};
struct userparam{
	int Dalay1;
	int Dalay2;
	int Dalay3;
};

class Common
{
public:
	Common(void);
	~Common(void);

	double m_MaxVoltage;
	double m_MinVoltage;
	double m_MaxCurrent;
	int m_ModulesNo;
	bool flagdlg;       // SwipeCardPortable��־
	int m_MAX_GUN;				//ǹ���ܺ�
	double m_voltage_coef;	//��ѹϵ��
	double m_current_coef;		//����ϵ��
	bool  m_ocpp_enable;

	//list <int>  m_user;//�������
	//struct user m_user;
	CArray<user, user> m_user;
	struct syspram m_syspara[2];
	struct userparam m_userpara;
	void ReadModuleConfig();
	void WriteModuleConfig()const;
	void ReadUser();
	void DeleteUser(CString user);
	void WriteUser();
	bool VerifyUser(CString user,CString pass);
	void Split(CString source, CStringArray& dest, CString division);
	BOOL  DirectoryList(LPCSTR Path);
	void find(LPCTSTR  lpPath,CStringArray& dest);
};
