#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_1_ChannelABiquadCoefficients

/* Number of Biquad sections are: 12 */

const uint8 CYCODE Filter_1_ChannelABiquadCoefficients[Filter_1_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0x12u, 0x2Eu, 0x02u, 0x00u, /* Section(0)_A0, 0.0340619087219238 */

 0x23u, 0x5Cu, 0x04u, 0x00u, /* Section(0)_A1, 0.0681235790252686 */

 0x12u, 0x2Eu, 0x02u, 0x00u, /* Section(0)_A2, 0.0340619087219238 */

 0x3Bu, 0xD5u, 0x31u, 0x00u, /* Section(0)_B1, -0.778639554977417 */

 0x5Cu, 0x62u, 0xE9u, 0x00u, /* Section(0)_B2, 0.353371620178223 */

 /* Coefficients of Section 1 */
 0xBDu, 0xE1u, 0x08u, 0x00u, /* Section(1)_A0, 0.1387779712677 */

 0x7Au, 0xC3u, 0x11u, 0x00u, /* Section(1)_A1, 0.2775559425354 */

 0xBDu, 0xE1u, 0x08u, 0x00u, /* Section(1)_A2, 0.1387779712677 */

 0x13u, 0x01u, 0x32u, 0x00u, /* Section(1)_B1, -0.781315565109253 */

 0xD2u, 0x81u, 0xE4u, 0x00u, /* Section(1)_B2, 0.429576396942139 */

 /* Coefficients of Section 2 */
 0x5Bu, 0xC6u, 0x08u, 0x00u, /* Section(2)_A0, 0.137106657028198 */

 0xB7u, 0x8Cu, 0x11u, 0x00u, /* Section(2)_A1, 0.274213552474976 */

 0x5Bu, 0xC6u, 0x08u, 0x00u, /* Section(2)_A2, 0.137106657028198 */

 0xDFu, 0x97u, 0x31u, 0x00u, /* Section(2)_B1, -0.77489447593689 */

 0xD0u, 0x0Du, 0xEDu, 0x00u, /* Section(2)_B2, 0.296031951904297 */

 /* Coefficients of Section 3 */
 0x9Bu, 0x50u, 0x09u, 0x00u, /* Section(3)_A0, 0.145544767379761 */

 0x35u, 0xA1u, 0x12u, 0x00u, /* Section(3)_A1, 0.291089296340942 */

 0x9Bu, 0x50u, 0x09u, 0x00u, /* Section(3)_A2, 0.145544767379761 */

 0x2Du, 0xFCu, 0x31u, 0x00u, /* Section(3)_B1, -0.78101658821106 */

 0x66u, 0xB6u, 0xDDu, 0x00u, /* Section(3)_B2, 0.535742282867432 */

 /* Coefficients of Section 4 */
 0x59u, 0x12u, 0x09u, 0x00u, /* Section(4)_A0, 0.14174485206604 */

 0xB1u, 0x24u, 0x12u, 0x00u, /* Section(4)_A1, 0.283489465713501 */

 0x59u, 0x12u, 0x09u, 0x00u, /* Section(4)_A2, 0.14174485206604 */

 0xEFu, 0x56u, 0x31u, 0x00u, /* Section(4)_B1, -0.770931005477905 */

 0xB2u, 0xE0u, 0xEFu, 0x00u, /* Section(4)_B2, 0.25191068649292 */

 /* Coefficients of Section 5 */
 0x64u, 0x6Cu, 0x08u, 0x00u, /* Section(5)_A0, 0.13161563873291 */

 0xC9u, 0xD8u, 0x10u, 0x00u, /* Section(5)_A1, 0.263231515884399 */

 0x64u, 0x6Cu, 0x08u, 0x00u, /* Section(5)_A2, 0.13161563873291 */

 0x6Fu, 0x19u, 0x31u, 0x00u, /* Section(5)_B1, -0.76717734336853 */

 0xD8u, 0x10u, 0xF2u, 0x00u, /* Section(5)_B2, 0.217721939086914 */

 /* Coefficients of Section 6 */
 0xC1u, 0x7Eu, 0x07u, 0x00u, /* Section(6)_A0, 0.117111444473267 */

 0x81u, 0xFDu, 0x0Eu, 0x00u, /* Section(6)_A1, 0.234222650527954 */

 0xC1u, 0x7Eu, 0x07u, 0x00u, /* Section(6)_A2, 0.117111444473267 */

 0x26u, 0xE3u, 0x30u, 0x00u, /* Section(6)_B1, -0.763864040374756 */

 0x14u, 0xC0u, 0xF3u, 0x00u, /* Section(6)_B2, 0.191401481628418 */

 /* Coefficients of Section 7 */
 0x17u, 0x9Au, 0x06u, 0x00u, /* Section(7)_A0, 0.103154897689819 */

 0x2Eu, 0x34u, 0x0Du, 0x00u, /* Section(7)_A1, 0.206309795379639 */

 0x17u, 0x9Au, 0x06u, 0x00u, /* Section(7)_A2, 0.103154897689819 */

 0x2Fu, 0xB6u, 0x30u, 0x00u, /* Section(7)_B1, -0.761119604110718 */

 0x90u, 0x04u, 0xF5u, 0x00u, /* Section(7)_B2, 0.171596527099609 */

 /* Coefficients of Section 8 */
 0xD1u, 0x5Fu, 0x06u, 0x00u, /* Section(8)_A0, 0.0995981693267822 */

 0xA3u, 0xBFu, 0x0Cu, 0x00u, /* Section(8)_A1, 0.199196577072144 */

 0xD1u, 0x5Fu, 0x06u, 0x00u, /* Section(8)_A2, 0.0995981693267822 */

 0xBCu, 0x93u, 0x30u, 0x00u, /* Section(8)_B1, -0.759016990661621 */

 0x0Fu, 0xEDu, 0xF5u, 0x00u, /* Section(8)_B2, 0.157406091690063 */

 /* Coefficients of Section 9 */
 0x18u, 0x40u, 0x06u, 0x00u, /* Section(9)_A0, 0.0976619720458984 */

 0x2Fu, 0x80u, 0x0Cu, 0x00u, /* Section(9)_A1, 0.195323705673218 */

 0x18u, 0x40u, 0x06u, 0x00u, /* Section(9)_A2, 0.0976619720458984 */

 0x7Au, 0x7Cu, 0x30u, 0x00u, /* Section(9)_B1, -0.75759744644165 */

 0x3Au, 0x83u, 0xF6u, 0x00u, /* Section(9)_B2, 0.148240566253662 */

 /* Coefficients of Section 10 */
 0x99u, 0x30u, 0x06u, 0x00u, /* Section(10)_A0, 0.0967161655426025 */

 0x31u, 0x61u, 0x0Cu, 0x00u, /* Section(10)_A1, 0.193432092666626 */

 0x99u, 0x30u, 0x06u, 0x00u, /* Section(10)_A2, 0.0967161655426025 */

 0xC4u, 0x70u, 0x30u, 0x00u, /* Section(10)_B1, -0.756882667541504 */

 0xEDu, 0xCCu, 0xF6u, 0x00u, /* Section(10)_B2, 0.143742322921753 */

 /* Coefficients of Section 11 */
 0xA6u, 0x6Au, 0x3Bu, 0x00u, /* Section(11)_A0, 0.928384304046631 */

 0x4Cu, 0xD5u, 0x76u, 0x00u, /* Section(11)_A1, 1.85676860809326 */

 0xA6u, 0x6Au, 0x3Bu, 0x00u, /* Section(11)_A2, 0.928384304046631 */

 0x26u, 0x6Cu, 0x31u, 0x00u, /* Section(11)_B1, -0.772225856781006 */

 0x1Cu, 0x29u, 0xD3u, 0x00u, /* Section(11)_B2, 0.700615882873535 */
};

