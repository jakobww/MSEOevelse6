/*******************************************************************************
* File Name: Signal_in.c  
* Version 2.0
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Signal_in.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Signal_in__PORT == 15 && ((Signal_in__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Signal_in_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Signal_in_Write(uint8 value) 
{
    uint8 staticBits = (Signal_in_DR & (uint8)(~Signal_in_MASK));
    Signal_in_DR = staticBits | ((uint8)(value << Signal_in_SHIFT) & Signal_in_MASK);
}


/*******************************************************************************
* Function Name: Signal_in_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Signal_in_DM_STRONG     Strong Drive 
*  Signal_in_DM_OD_HI      Open Drain, Drives High 
*  Signal_in_DM_OD_LO      Open Drain, Drives Low 
*  Signal_in_DM_RES_UP     Resistive Pull Up 
*  Signal_in_DM_RES_DWN    Resistive Pull Down 
*  Signal_in_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Signal_in_DM_DIG_HIZ    High Impedance Digital 
*  Signal_in_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Signal_in_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Signal_in_0, mode);
}


/*******************************************************************************
* Function Name: Signal_in_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Signal_in_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Signal_in_Read(void) 
{
    return (Signal_in_PS & Signal_in_MASK) >> Signal_in_SHIFT;
}


/*******************************************************************************
* Function Name: Signal_in_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Signal_in_ReadDataReg(void) 
{
    return (Signal_in_DR & Signal_in_MASK) >> Signal_in_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Signal_in_INTSTAT) 

    /*******************************************************************************
    * Function Name: Signal_in_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Signal_in_ClearInterrupt(void) 
    {
        return (Signal_in_INTSTAT & Signal_in_MASK) >> Signal_in_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
