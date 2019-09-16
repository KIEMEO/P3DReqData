struct InterfaceF35Data
{
	bool bLandingLightSwitch;       //// 
	bool bLandingGearUp;                
	bool bLandingGearDown;
	bool bJettisonAll;           //三位开关all位置        弹射投掷 游戏无反应
	bool bJettisonExt;            //三位开关Ext位置      如果两个都是false 则在 SEl 位置
	bool bPakingBreak;           //on and off
	bool bAutoRecover1;           // 按下
	bool bAutoRecover2;          //弹起
	bool bBorUBatt1;            //游戏内无反应
	bool bBorUBatt2;            //游戏内无反应
	bool bFtaOff1;             //游戏内无反应
	bool bFtaOff2;             //游戏内无反应
	bool bHMDMODE;             //为true时  在上位置   否则 下位置
	bool bHMDOFF;              //旋钮位置off位置
	bool bHMDNIGHT;            //旋钮位置night位置
	bool bHMDAUTO;            //旋钮位置auto位置       前三个位置为false时默认第四个旋钮位置day位置
	bool bHDMSBRT;              //按钮上下位置
    bool bHDMSCNT;              //按钮 上为true 默认false 	
	bool bMFDOFF;                //MFD 旋钮off位置
	bool bMFDNight;               //MFD旋钮 night位置
	bool bMFDDay;                 //MFD旋钮 day位置
	bool bMasterArmup;              //masterarm 在上 位置    否则 默认在下	
    bool bHookStovl;                  //Arresting hook handle        ////SET_TAIL_HOOK_HANDLE 时间  
	bool bGearExtension;              //emergency gear handle	
	double dCommunicationCom1;        //A旋钮
	double dCommunicationCom2;         //B旋钮
	double dNavigationRadio;           //C/BUR旋钮
	bool bStrobeLightSwitch;            //拨动开关 默认off位置    为true时在on位置
	bool bNavigationLightSwitch;        //拨动开关  默认off 位置  为true时 在on位置c
	bool bLogoLightSwitch;              //拨动开关  默认off 位置  为true时 在on
	bool bCabinLightSwitch;             //拨动开关  默认off 位置  为true时 在on
	bool bEngineIcc2;                   //拨动开关  默认下 位置   为true时在上位置
	bool bEngineIcc1;                   //拨动开关  默认下 位置  为true时在上位置
	bool bBatt28v;                      //拨动开关     不处理  游戏中与batt开关联动
	bool bBatt270v;                     //拨动开关     不处理  游戏中与batt开关联动
	bool bBattSwitch;                    //Batt开关  默认在下位置  为true时波动上方位置
	bool bButtonNone;                    //不知名按钮   游戏中无法触发 只能弹起按钮盖
	bool bGeneratorSwitchoff;            //三位旋钮    旋钮off位置
	bool bGeneratorSwitchauto;           //三位旋钮    旋钮auto位置      前两个位置均为false时 start 位置
};
struct ControlF35Data
{
	double dLandingLightSwitch;            //   LIGHT LANDING                 变量
    double dLandingGear;                   //	GEAR HANDLE POSITION          变量
	double dPakingBreak;                  //    BRAKE PARKING POSITION        变量

};

struct sInAH1ZData             //DI 或者AI 采集   AI+DI 顺序
{
	double HelicpterAcceRod;        // 直升机总距杆 杆位移  
	double IcsKnobButton;            //ICS旋钮
	bool bLeftLight1;               //遮光板第一个灯
	bool bLeftLight2;               //左2灯
	bool bLeftLight3;               //遮光板左3灯
	bool bLeftLight4;               //左遮光板“日”字灯
	bool bRightCautionLight;        //caution 灯
	bool bRightLight2;              //遮光板右2灯
	bool bRightLight3;              //右3灯
	bool bRightLight4;              //右4田字灯
	bool bRighNavGps;               //Nav GPS灯合成一个
	bool bRadioCall;                //遮光罩上radio灯  应该是一直处于常量状态
	bool bAcceRodButton7;           //总距杆按钮7  A2+1 DI13
	bool bEngineButton_17;           //发动机控制板按钮17 A2+1 DI14
	bool bDCBUSLIghtUp;               //DC BUs 上灯 A2+3 DI0
	bool bLightUpGEN_1;               //GEN1 上的灯 A2+3 DI1
	bool bLightUpGEN_2;               //gen2上的灯  A2+3 DI2
	bool bAVIOIUCUpLight;             //avioiuc上灯  A2+3 DI3
	bool bBATTLight;              //BATT灯  A2+3 DI4
	bool bBaTTAuxLight;            //baTT aux灯  A2+3 DI5
	bool bEXIPWRLight;             //EXIPwr 上灯  A2+3 DI6
	bool bNoneNameLight8;          //第8个位置的灯  A2+3 DI7
	bool bNONENameLight9;          //第九个位置灯  A2+3 DI8
	//bool bNonwNameLight10;           //未接线   无此灯  A2+3 DI9
	bool bAcceRodButton1;           //总距杆 按钮1   A2+3 DI10
	bool bAcceRodButton2;           //总距杆 按钮2   A2+3 DI11
	bool bAcceRodButton3;
	bool bAcceRodButton4;
	bool bAcceRodButton5;
	bool bAcceRodButton6;            //总距杆 按钮7  A2+3 DI15
	bool bEngineButton_1;            //发动机面板控制按钮1  A2+5 DI0
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
	bool bEngineButton_16;           ///发动机面板控制按钮1  A2+5 DI15

};
struct sOutAH1ZData             //DO 输出数据
{
	bool bLeftLight1;               //遮光板第一个灯
	bool bLeftLight2;
	bool bLeftLight3;               //遮光板左3灯
	bool bLeftLight4;               //左遮光板“日”字灯
	bool bRightCautionLight;        //caution 灯
	bool bRightLight2;              //遮光板右2灯
	bool bRightLight3;              //右3灯
	bool bRightLight4;              //右4田字灯
	bool bRighNavGps;               //Nav GPS灯合成一个
	bool bRadioCall;                //遮光罩上radio灯    应该是一致处于长亮状态
	bool bAutoEngineeLight;         //auto 指示灯
};