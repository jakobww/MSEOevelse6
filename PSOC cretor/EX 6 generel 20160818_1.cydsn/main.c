/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>

#define n 1
#define N_Sample 10

int16 	V_Sample[n];
int32 	V_Sample_SUM_1=0;
float 	V_Sample_SUM_2=0;
int16 	V_Sample_MIN=0;
int16 	V_Sample_MAX=0;
int16 	V_Sample_AVG=0;
float 	V_Sample_VAR=0;
float 	V_Sample_AVG_float=0;
float 	V_Sample_PP_float=0;
float 	V_Sample_RMS_float=0;
uint16 	i=0;

void DMA_1_Config()
{
	/* Variable declarations for DMA_1 */
	/* Move these variable declarations to the top of the function */
	uint8 DMA_1_Chan;
	uint8 DMA_1_TD[1];

	/* DMA Configuration for DMA_1 */
	#define DMA_1_BYTES_PER_BURST 2
	#define DMA_1_REQUEST_PER_BURST 1
	#define DMA_1_SRC_BASE (CYDEV_PERIPH_BASE)
	#define DMA_1_DST_BASE (CYDEV_PERIPH_BASE)
	DMA_1_Chan = DMA_1_DmaInitialize(DMA_1_BYTES_PER_BURST, DMA_1_REQUEST_PER_BURST, 
	    HI16(DMA_1_SRC_BASE), HI16(DMA_1_DST_BASE));
	DMA_1_TD[0] = CyDmaTdAllocate();
	CyDmaTdSetConfiguration(DMA_1_TD[0], 2, DMA_INVALID_TD, TD_INC_DST_ADR);
	CyDmaTdSetAddress(DMA_1_TD[0], LO16((uint32)ADC_DelSig_1_DEC_SAMP_PTR), LO16((uint32)Filter_1_STAGEAM_PTR));
	CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);
	CyDmaChEnable(DMA_1_Chan, 1);
}

void DMA_2_Config()
{
/* Variable declarations for DMA_2 */
/* Move these variable declarations to the top of the function */
uint8 DMA_2_Chan;
uint8 DMA_2_TD[1];

/* DMA Configuration for DMA_2 */
#define DMA_2_BYTES_PER_BURST 2
#define DMA_2_REQUEST_PER_BURST 1
#define DMA_2_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_2_DST_BASE (CYDEV_SRAM_BASE)
DMA_2_Chan = DMA_2_DmaInitialize(DMA_2_BYTES_PER_BURST, DMA_2_REQUEST_PER_BURST, 
    HI16(DMA_2_SRC_BASE), HI16(DMA_2_DST_BASE));
DMA_2_TD[0] = CyDmaTdAllocate();
CyDmaTdSetConfiguration(DMA_2_TD[0], 2, DMA_INVALID_TD,  DMA_2__TD_TERMOUT_EN | TD_INC_SRC_ADR );
CyDmaTdSetAddress(DMA_2_TD[0], LO16((uint32)Filter_1_HOLDAM_PTR), LO16((uint32)V_Sample));
CyDmaChSetInitialTd(DMA_2_Chan, DMA_2_TD[0]);
CyDmaChEnable(DMA_2_Chan, 1);

}

CY_ISR(DAC_int)
{
	test_01_Write(1);
	VDAC8_1_Data = ((int8)(V_Sample[0] >> 8))+156;
	test_01_Write(0);
}

CY_ISR(Sample_int)
{
    	test_01_Write(1);
	Control_Reg_1_Control=0;
	V_Sample_SUM_1=V_Sample_SUM_1+V_Sample[0];
	V_Sample_SUM_2=V_Sample_SUM_2+(((float)V_Sample[0])*((float)V_Sample[0]));
	if(V_Sample[0]<V_Sample_MIN)V_Sample_MIN=V_Sample[0];
	if(V_Sample[0]>V_Sample_MAX)V_Sample_MAX=V_Sample[0];
	test_01_Write(0);
}

void Init()
{
	ADC_DelSig_1_Start();
	ADC_DelSig_1_SetCoherency(ADC_DelSig_1_COHER_MID);
	ADC_DelSig_1_StartConvert();
	DMA_1_Config();
	Filter_1_Start();
	Filter_1_SetCoherency(Filter_1_CHANNEL_A, Filter_1_KEY_HIGH);
	DMA_2_Config();
	isr_1_StartEx(DAC_int);
	VDAC8_1_Start();
	isr_2_StartEx(Sample_int);
	Control_Reg_1_Control=0;
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	Init();

	CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */

    for(;;)
    {
        /* Place your application code here. */

		V_Sample_SUM_1=0;
		V_Sample_SUM_2=0;
		V_Sample_MIN= ((1<<15)-1) ; // int: ((1<<15)-1) uint: 0-1 
		V_Sample_MAX=1 << 15;       // int: 1<<15       uint: 0
		for(i=0;i<(1 << (N_Sample));i++)
		{
			Control_Reg_1_Control=1;
			while(Control_Reg_1_Control); 
		}
		V_Sample_AVG=V_Sample_SUM_1 >> (N_Sample);
		if(V_Sample_SUM_2>((float)V_Sample_AVG)*((float)V_Sample_AVG))
		{
			V_Sample_VAR=(V_Sample_SUM_2/( 1 << N_Sample))-((float)V_Sample_AVG)*((float)V_Sample_AVG);
		}
		else
		{
			V_Sample_VAR=0;
		}
		V_Sample_AVG_float=ADC_DelSig_1_CountsTo_Volts(V_Sample_AVG);
		V_Sample_PP_float=ADC_DelSig_1_CountsTo_Volts((((int32)V_Sample_MAX)-((int32)V_Sample_MIN)));
		V_Sample_RMS_float=ADC_DelSig_1_CountsTo_Volts((int32)sqrt(V_Sample_VAR));       
    }
}

/* [] END OF FILE */




