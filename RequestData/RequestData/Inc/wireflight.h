
#ifndef _WireForData_F35_
#define _WireForData_F35_

struct InterfaceF35Data{
	bool bLandingLightSwitch;       //// 
	bool bLandingGearUp;
	bool bLandingGearDown;
	bool bJettisonAll;           //��λ����allλ��        ����Ͷ�� ��Ϸ�޷�Ӧ
	bool bJettisonExt;            //��λ����Extλ��      �����������false ���� SEl λ��
	bool bPakingBreak;           //on and off
	bool bAutoRecover1;           //����
	bool bAutoRecover2;          //����
	bool bBorUBatt1;            //��Ϸ���޷�Ӧ
	bool bBorUBatt2;            //��Ϸ���޷�Ӧ
	bool bFtaOff1;             //��Ϸ���޷�Ӧ
	bool bFtaOff2;             //��Ϸ���޷�Ӧ
	bool bHMDMODE;             //Ϊtrueʱ  ����λ��   ���� ��λ��
	bool bHMDOFF;              //��ťλ��offλ��
	bool bHMDNIGHT;            //��ťλ��nightλ��
	bool bHMDAUTO;            //��ťλ��autoλ��       ǰ����λ��ΪfalseʱĬ�ϵ��ĸ���ťλ��dayλ��
	bool bHDMSBRT;              //��ť����λ��
	bool bHDMSCNT;              //��ť ��Ϊtrue Ĭ��false 	
	bool bMFDOFF;                //MFD ��ťoffλ��
	bool bMFDNight;               //MFD��ť nightλ��
	bool bMFDDay;                 //MFD��ť dayλ��
	bool bMasterArmup;              //masterarm ���� λ��    ���� Ĭ������	
	bool bHookStovl;                  //Arresting hook handle        ////SET_TAIL_HOOK_HANDLE ʱ��  
	bool bGearExtension;              //emergency gear handle	
	bool dCommunicationCom1;        //A��ť
	bool dCommunicationCom2;         //B��ť
	bool dNavigationRadio;           //C/BUR��ť
	bool bStrobeLightSwitch;            //�������� Ĭ��offλ��    Ϊtrueʱ��onλ��
	bool bNavigationLightSwitch;        //��������  Ĭ��off λ��  Ϊtrueʱ ��onλ��c
	bool bLogoLightSwitch;              //��������  Ĭ��off λ��  Ϊtrueʱ ��on
	bool bCabinLightSwitch;             //��������  Ĭ��off λ��  Ϊtrueʱ ��on
	bool bEngineIcc2;                   //��������  Ĭ���� λ��   Ϊtrueʱ����λ��
	bool bEngineIcc1;                   //��������  Ĭ���� λ��  Ϊtrueʱ����λ��
	bool bBatt28v;                      //��������     ������  ��Ϸ����batt��������
	bool bBatt270v;                     //��������     ������  ��Ϸ����batt��������
	bool bBattSwitch;                    //Batt����  Ĭ������λ��  Ϊtrueʱ�����Ϸ�λ��
	bool bButtonNone;                    //��֪����ť   ��Ϸ���޷����� ֻ�ܵ���ť��
	bool bGeneratorSwitchoff;            //��λ��ť    ��ťoffλ��
	bool bGeneratorSwitchauto;           //��λ��ť    ��ťautoλ��      ǰ����λ�þ�Ϊfalseʱ start λ��
};
struct ControlF35Data
{
	double dLandingLightSwitch;            //   LIGHT LANDING                 ����    bool
	double dLandingGear;                   //	GEAR HANDLE POSITION          ����    ��λ���� 1 ���� �� 0   
	double dPakingBreak;                  //    BRAKE PARKING POSITION        ����     
	double dAVionMasterSwitch;               // AVIONICS MASTER SWITCH    ��ť    bool
	double dTaiHookHandle;                   // TAILHOOK HANDLE     true �����蹳
	double dStrobeLight;                     // LIGHT STROBE            bool
	double dNavLight;                        //  LIGHT NAV
	double dLogoLight;                       //   LIGHT LOGO
	double dCabinLight;                      //  LIGHT CABIN
	double dBattSwitch;                      //   ELECTRICAL MASTER BATTERY
	double dGentorSwitch;                    // GENERAL ENG GENERATOR SWITCH:1
};

//DI ����AI �ɼ�   AI+DI ˳��
struct sInAH1ZData
{
	int HelicpterAcceRod;        // ֱ�����ܾ�� ��λ��  
	int IcsKnobButton;           //ICS��ť
	bool bLeftLight1;               //�ڹ���һ����
	bool bLeftLight2;               //��2��
	bool bLeftLight3;               //�ڹ����3��
	bool bLeftLight4;               //���ڹ�塰�ա��ֵ�
	bool bRightCautionLight;        //caution ��
	bool bRightLight2;              //�ڹ����2��
	bool bRightLight3;              //��3��
	bool bRightLight4;              //��4���ֵ�
	bool bRighNavGps;               //Nav GPS�ƺϳ�һ��
	bool bRadioCall;                //�ڹ�����radio��  Ӧ����һֱ���ڳ���״̬
	bool bAcceRodButton7;           //�ܾ�˰�ť7  A2+1 DI13
	bool bEngineButton_17;           //���������ư尴ť17 A2+1 DI14
	bool bDCBUSLIghtUp;               //DC BUs �ϵ� A2+3 DI0
	bool bLightUpGEN_1;               //GEN1 �ϵĵ� A2+3 DI1
	bool bLightUpGEN_2;               //gen2�ϵĵ�  A2+3 DI2
	bool bAVIOIUCUpLight;             //avioiuc�ϵ�  A2+3 DI3
	bool bBATTLight;              //BATT��  A2+3 DI4
	bool bBaTTAuxLight;            //baTT aux��  A2+3 DI5
	bool bEXIPWRLight;             //EXIPwr �ϵ�  A2+3 DI6
	bool bNoneNameLight8;          //��8��λ�õĵ�  A2+3 DI7
	bool bNONENameLight9;          //�ھŸ�λ�õ�  A2+3 DI8
	//bool bNonwNameLight10;           //δ����   �޴˵�  A2+3 DI9
	bool bAcceRodButton1;           //�ܾ�� ��ť1   A2+3 DI10
	bool bAcceRodButton2;           //�ܾ�� ��ť2   A2+3 DI11
	bool bAcceRodButton3;
	bool bAcceRodButton4;
	bool bAcceRodButton5;
	bool bAcceRodButton6;            //�ܾ�� ��ť7  A2+3 DI15
	bool bEngineButton_1;            //�����������ư�ť1  A2+5 DI0
	bool bEngineButton_2;
	bool bEngineButton_3;
	bool bEngineButton_4;
	bool bEngineButton_5;
	bool bEngineButton_6;
	bool bEngineButton_7;
	bool bEngineButton_8;
	bool bEngineButton_9;
	bool bEngineButton_10;
	bool bEngineButton_11;
	bool bEngineButton_12;
	bool bEngineButton_13;
	bool bEngineButton_14;
	bool bEngineButton_15;
	bool bEngineButton_16;           ///�����������ư�ť1  A2+5 DI15
};

//DO �������
struct sOutAH1ZData
{
	bool bLeftLight1;               //�ڹ���һ����
	bool bLeftLight2;
	bool bLeftLight3;               //�ڹ����3��
	bool bLeftLight4;               //���ڹ�塰�ա��ֵ�
	bool bRightCautionLight;        //caution ��
	bool bRightLight2;              //�ڹ����2��
	bool bRightLight3;              //��3��
	bool bRightLight4;              //��4���ֵ�
	bool bRighNavGps;               //Nav GPS�ƺϳ�һ��
	bool bRadioCall;                //�ڹ�����radio��    Ӧ����һ�´��ڳ���״̬
	bool bAutoEngineeLight;         //auto ָʾ��
};


#endif
