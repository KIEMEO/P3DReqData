
//------------------------------------------------------------------------------
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "SimConnect.h"
#include <strsafe.h>
#include <winsock.h>

#pragma comment(lib,"ws2_32.lib")
int     quit = 0;
HANDLE  hSimConnect = NULL;



WSADATA wsaData;                                    //指向WinSocket信息结构的指针
SOCKET serSocket;                                //创建套接字
SOCKADDR_IN serUdpServ, clientAddr;                              //指向通信对象的结构体指针 
const char* cUdpLocal = "10.10.10.11";    //本机ip地址
const char* cUdpAddr = "10.10.10.19";    //Udp发送地址

struct DcsData
{
	float airSpeed = 0;
	float angleOfAttack = 0;
	float angleOfSideSlip = 0;
	float verticalVelocity = 0;
	float pitch = 0;
	float bank = 0;
	float yaw = 0;
	float trueAirSpeed = 0;
	float radioAltitude = 0;
	float mach = 0;
	float altitude = 0;
	float magneticYaw = 0;
};

struct DcsData1
{
	double airSpeed = 0;
	double angleOfAttack = 0;
	double angleOfSideSlip = 0;
	double verticalVelocity = 0;
	double pitch = 0;
	double bank = 0;
	double yaw = 0;
	double trueAirSpeed = 0;
	double radioAltitude = 0;
	double mach = 0;
	double altitude = 0;
	double magneticYaw = 0;
};

const char* pname[] =                        //需要输出的变量名字   按照手册中字符串写   不区分大小写
{
	"AIRSPEED INDICATED",
	"ANGLE OF ATTACK INDICATOR",
	"INCIDENCE BETA",
	"VERTICAL SPEED",
	"PLANE PITCH DEGREES",
	"PLANE BANK DEGREES",
	"HEADING INDICATOR",
	"AIRSPEED TRUE",
	"RADIO HEIGHT",
	"AIRSPEED MACH",
	"PLANE ALTITUDE",
	"PLANE HEADING DEGREES MAGNETIC"
};
const char* punit[] =                       //需要输出的变量单位    按照手册中变量的单位写   
{
	"Knots",
	"Radians",
	"Radians",
	"Feet per second",
	"Radians",
	"Radians",
	"Radians",
	"Knots",
	"Feet",
	"Mach",
	"Feet",
	"Radians"
};

enum EVENT_ID {
	EVENT_SIM_START,
	EVENT_BRAKES,
	EVENT_MY_EVENT,
	EVENT_MASKABLE,
};

enum DATA_DEFINE_ID {
	DEFINITION_1,
	DEFINITION_6,
	DEFINITION_test,
};

enum DATA_REQUEST_ID {
	REQUEST_1,
};

DcsData1 * pS1;
DcsData* pS;

void CALLBACK MyDispatchProcRD(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
{
	HRESULT hr;

	switch (pData->dwID)
	{
	case SIMCONNECT_RECV_ID_EVENT:
	{
		SIMCONNECT_RECV_EVENT* evt = (SIMCONNECT_RECV_EVENT*)pData;

		switch (evt->uEventID)
		{
		case EVENT_SIM_START:

			// Now the sim is running, request information on the user aircraft
			//hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, REQUEST_1, DEFINITION_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);

			break;

		default:
			break;
		}
		break;
	}

	case SIMCONNECT_RECV_ID_SIMOBJECT_DATA_BYTYPE:
	{
		SIMCONNECT_RECV_SIMOBJECT_DATA_BYTYPE* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA_BYTYPE*)pData;

		switch (pObjData->dwRequestID)
		{
		case REQUEST_1:
		{
			DWORD ObjectID = pObjData->dwObjectID;
			pS1 = (DcsData1*)& pObjData->dwData;
			pS->airSpeed = pS1->airSpeed;
			pS->altitude = pS1->altitude;
			pS->angleOfAttack = pS1->angleOfAttack*57.3;
			pS->angleOfSideSlip = pS1->angleOfSideSlip * 57.3;
			pS->bank = -pS1->bank * 57.3;
			pS->mach = pS1->mach;
			pS->magneticYaw = pS1->magneticYaw * 57.3;
			pS->pitch = -pS1->pitch * 57.3;
			pS->radioAltitude = pS1->radioAltitude;
			pS->trueAirSpeed = pS1->trueAirSpeed;
			pS->verticalVelocity = pS1->verticalVelocity;
			pS->yaw = pS1->yaw * 57.3;

			//printf("%f\n", pS->pitch);
			char* pPack = (char*)pS;
			sendto(serSocket, pPack, sizeof(DcsData), 0, (struct sockaddr*) & clientAddr, sizeof(clientAddr));
			break;
		} 

		default:
			break;
		}
		break;
	}


	case SIMCONNECT_RECV_ID_QUIT:
	{
		quit = 1;
		break;
	}

	default:
		printf("\nReceived:%d", pData->dwID);
		break;
	}
}

void testDataRequest()
{
	HRESULT hr;
	while (!SUCCEEDED(SimConnect_Open(&hSimConnect, "Request Data", NULL, 0, 0, 0)))
	{
		Sleep(1000);
	}
	    printf("\nConnected to Prepar3D!");
		HWND hw1 = ::FindWindowA(NULL, "RequestData");//获取程序句柄
		ShowWindow(hw1, SW_MINIMIZE);

		for (int j = 0; j < 12; ++j)
		{
			hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, pname[j], punit[j]);
		}

		pS = new DcsData;
		memset(pS,0,sizeof(DcsData));
		pS1 = new DcsData1;
		memset(pS1, 0, sizeof(DcsData1));

		/*Sleep(5000);
		SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_MY_EVENT, "PANEL_4");

		SimConnect_TransmitClientEvent(hSimConnect, 0, EVENT_MY_EVENT, 0, SIMCONNECT_GROUP_PRIORITY_HIGHEST, SIMCONNECT_EVENT_FLAG_GROUPID_IS_PRIORITY);

		hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, REQUEST_1, DEFINITION_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);

		Sleep(5000);*/
		hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, REQUEST_1, DEFINITION_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
		
		while (0 == quit)
		{
			SimConnect_CallDispatch(hSimConnect, MyDispatchProcRD, NULL);
			hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, REQUEST_1, DEFINITION_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
			Sleep(50);
		}

		hr = SimConnect_Close(hSimConnect);
}

int __cdecl _tmain(int argc, _TCHAR* argv[])
{
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)     //进行WinSocket的初始化
	{
		printf("Can't initiates windows socket!Program stop.\n");//初始化失败返回-1
		return -1;
	}
	//********************   建立一个数据报类型的UDP套接字  ******************//
	serSocket = socket(PF_INET, SOCK_DGRAM, 0);

	serUdpServ.sin_family = AF_INET;
	//serUdpServ.sin_addr.s_addr = inet_addr(cUdpLocal);
	serUdpServ.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	serUdpServ.sin_port = htons(9001);

	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(33166);
	clientAddr.sin_addr.s_addr = inet_addr(cUdpAddr);

	if (bind(serSocket, (sockaddr*)& serUdpServ, sizeof(serUdpServ)) == SOCKET_ERROR)
	{
		printf("bind error !");
		closesocket(serSocket);
		return 0;
	}

	testDataRequest();

	closesocket(serSocket);         //关闭监听socket
	WSACleanup();
	return 0;
}




