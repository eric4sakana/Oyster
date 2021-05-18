/* 
 * Project : fnbms_bsw_ES11_B
 * Component: /CANRx_DEBUG_ASILC_SWC/SwcComponents/CANRx_DEBUG_ASILC
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 7.0.1
 * Author: myaccount
 * Date : ������ ���� 23 08:36:25 2021
 ****************************************************************************/

#include "Rte_CANRx_DEBUG_ASILC.h"

/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :CANRx_DEBUG_ASILC_Process_10ms) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :CANRx_DEBUG_ASILC_Process_10ms) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :CANRx_DEBUG_ASILC_Process_10ms) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define CANRx_DEBUG_ASILC_START_SEC_CODE                   
#include "CANRx_DEBUG_ASILC_MemMap.h"


/*********** my declaration******/

#define CUR_CONST1	8388608

uint8 Currt_CRC_Check(uint8 Seq_IP, uint8 S_PowerS, uint8 S_InErr, uint8 Safe_G_V, uint32 A_Currt, uint16 D_Currt, uint8 Sw_Build, uint8 CRC_IP);
uint8 Byte_merge1(uint8 SequenceIP, uint8 StatusPowerSupply, uint8 StatusInternalError, uint8 SaftyGoalViolation);
uint16 CRC8_SAE_J1850(uint16 crc, uint8 *data, uint8 len);
uint8 State_Check_1(uint8 S_Ip, uint8 A_Cur_Err_S);
float32 Currt_Subsystem7(uint32 Currt_In);


/*********** my declaration end******/

FUNC (void, CANRx_DEBUG_ASILC_CODE) CANRx_DEBUG_ASILC_Process_10ms/* return value & FctID */
(
		void
)
{

	uint32 read1;
	Std_ReturnType retRead1;
	uint8 read2;
	Std_ReturnType retRead2;
	uint8 read3;
	Std_ReturnType retRead3;
	uint16 read4;
	Std_ReturnType retRead4;
	uint8 read5;
	Std_ReturnType retRead5;
	uint8 read6;
	Std_ReturnType retRead6;
	uint8 read7;
	Std_ReturnType retRead7;
	uint8 read8;
	Std_ReturnType retRead8;
	float32 write9;
	Std_ReturnType retWrite9;
	uint8 write10;
	Std_ReturnType retWrite10;
	uint8 write11;
	Std_ReturnType retWrite11;
	uint16 write12;
	Std_ReturnType retWrite12;
	uint8 write13;
	Std_ReturnType retWrite13;
	uint8 write14;
	Std_ReturnType retWrite14;
	uint8 write15;
	Std_ReturnType retWrite15;
	uint8 write16;
	Std_ReturnType retWrite16;
	uint8 write17;
	Std_ReturnType retWrite17;

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :CANRx_DEBUG_ASILC_Process_10ms) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	retRead1 = Rte_Read_R_SG_DebugCANInfos_ASILC_AnalogCurrent(&read1);
	retRead2 = Rte_Read_R_SG_DebugCANInfos_ASILC_statusinternalError(&read2);
	retRead3 = Rte_Read_R_SG_DebugCANInfos_ASILC_CRC_IP(&read3);
	retRead4 = Rte_Read_R_SG_DebugCANInfos_ASILC_DigitalCurrent(&read4);
	retRead5 = Rte_Read_R_SG_DebugCANInfos_ASILC_safetyGoalViolation(&read5);
	retRead6 = Rte_Read_R_SG_DebugCANInfos_ASILC_SequenceCounterIp(&read6);
	retRead7 = Rte_Read_R_SG_DebugCANInfos_ASILC_SoftwareBuild(&read7);
	retRead8 = Rte_Read_R_SG_DebugCANInfos_ASILC_StatusPowerSupply(&read8);

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */
	
	//CRC check. Output is CRC_IP
	write11 = Currt_CRC_Check(read6, read8, read2, read5, read1, read4, read7, read3);

	//AnalogCurrent process
	write9 = Currt_Subsystem7(read1);

	//0x3C2State
	write17 = State_Check_1(read6, retRead1);

	//port with direct connections
	write10 = read2;
	write12 = read4;
	write13 = read5;
	write14 = read6;
	write15 = read7;
	write16 = read8;





	/*  -------------------------------------- Data Write ----------------------------------------  */
	retWrite9 = Rte_Write_P_CANRx_DEGInfos_ASILC_AnalogCurrent(write9);
	retWrite10 = Rte_Write_P_CANRx_DEGInfos_ASILC_statusinternalError(write10);
	retWrite11 = Rte_Write_P_CANRx_DEGInfos_ASILC_CRC_IP(write11);
	retWrite12 = Rte_Write_P_CANRx_DEGInfos_ASILC_DigitalCurrent(write12);
	retWrite13 = Rte_Write_P_CANRx_DEGInfos_ASILC_safetyGoalViolation(write13);
	retWrite14 = Rte_Write_P_CANRx_DEGInfos_ASILC_SequenceCounterIp(write14);
	retWrite15 = Rte_Write_P_CANRx_DEGInfos_ASILC_SoftwareBuild(write15);
	retWrite16 = Rte_Write_P_CANRx_DEGInfos_ASILC_StatusPowerSupply(write16);
	retWrite17 = Rte_Write_P_CANRx_DEBUG_Current_0x3C2State_Current_0x3C2State(write17);

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :CANRx_DEBUG_ASILC_Process_10ms) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

#define CANRx_DEBUG_ASILC_STOP_SEC_CODE                       
#include "CANRx_DEBUG_ASILC_MemMap.h"
#define CANRx_DEBUG_ASILC_START_SEC_CODE                   
#include "CANRx_DEBUG_ASILC_MemMap.h"
FUNC (void, CANRx_DEBUG_ASILC_CODE) CANRx_DEBUG_ASILC_Init/* return value & FctID */
(
		void
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :CANRx_DEBUG_ASILC_Init) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :CANRx_DEBUG_ASILC_Init) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

// CRC check for CAB1500 data
uint8 Currt_CRC_Check(uint8 Seq_IP, uint8 S_PowerS, uint8 S_InErr, uint8 Safe_G_V, uint32 A_Currt, uint16 D_Currt, uint8 Sw_Build, uint8 CRC_IP)
{
    //save 64bits CAB1500 data
    uint8 AA[8];
    uint16 CRC_Result;
    uint8 CRC8_Out;
	
	//XOR_Value is 0xffu
	CRC_IP^=0xff;
    CRC8_Out = 0;
    CRC_Result = 0;
    AA[0] = Byte_merge1(Seq_IP, S_PowerS, S_InErr, Safe_G_V);
    AA[1] = (A_Currt>>16) & 0xff;
    AA[2] = (A_Currt>>8) & 0xff;
    AA[3] = A_Currt & 0xff;
    AA[4] = (D_Currt>>8) & 0xff;
    AA[5] = D_Currt & 0xff;
    AA[6] = Sw_Build;
    AA[7] = CRC_IP;

    CRC_Result = CRC8_SAE_J1850(CRC_Result, AA, 8);

    if(CRC_Result !=0)
    {
        CRC8_Out = 1;
    }

	//  0  CRC check passed
	//  1  CRC check failed
    return CRC8_Out;

}
//merging SequenceIP, StatusPowerSupply, StatusInternalError, SaftyGoalViolation into 1 single byte
uint8 Byte_merge1(uint8 SequenceIP, uint8 StatusPowerSupply, uint8 StatusInternalError, uint8 SaftyGoalViolation)
{
	uint8 A_Temp = 0x00;

    A_Temp^=(SequenceIP<<4);
    A_Temp^=(StatusPowerSupply<<2);
    A_Temp^=(StatusInternalError<<1);
    A_Temp^=(SaftyGoalViolation);
    return A_Temp;

}
//CRC-8 SAE J1850 check
uint16 CRC8_SAE_J1850(uint16 crc, uint8 *data, uint8 len)
{

    crc ^= 0xffff;
    while (len--) 
	{
        crc ^= *data++;
        for (uint8 k = 0; k < 8; k++)
		{
			crc = crc & 0x80 ? (crc << 1) ^ 0x1d : crc << 1;
		}
            
    }
    crc &= 0xffff;
    crc ^= 0x0000;
    return crc;
}

//current processing
float32 Currt_Subsystem7(uint32 Currt_In)
{

    float32 LemCab_Currt;

    LemCab_Currt =((float32)Currt_In-CUR_CONST1)*0.001;

    return LemCab_Currt;
}


//0x3C2State reset after 1s 
uint8 State_Check_1(uint8 S_Ip, uint8 A_Cur_Err_S)
{
    
    static uint8 CommnCnt = 0;
    static uint8 Commnstate = 0;
    uint8 Currt_0x3C2State_write;
    
    if(!S_Ip)
    {
        CommnCnt++;
		//delay 1 second
        if(CommnCnt>=100)
        {
            Commnstate = 1;
            CommnCnt = 100;
        }
        
    }
    else
    {
        CommnCnt = 0;
        Commnstate = 0;
    }


    if(A_Cur_Err_S > 0 || Commnstate > 0)
    {
        Currt_0x3C2State_write = 64;
    }
    else
    {
        Currt_0x3C2State_write = 0;
    }

    //   64  error
    //    0  normal
    return Currt_0x3C2State_write;
}

//
#define CANRx_DEBUG_ASILC_STOP_SEC_CODE                       
#include "CANRx_DEBUG_ASILC_MemMap.h"

1234