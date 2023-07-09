# Pawn Big Numbers

### Description
This plugin is made for my own project gamemode that will use larger amount of numbers that 32 bit systems can't handle (overflow).

### Usage
> **Note**   
> The numbers are supposedly to be a string in order for this to work.

 - BigNumber_AddFloatNumber(const num1[], const num2[], output[], len = sizeof(output))
    - This native will add two floating point numbers.
    
 - BigNumber_FormatFloatNumber(const number[], const delimiter[] = ",", output[], len = sizeof(output))
    - This native will format floating point numbers (separate with delimiter)

 - bool:BigNumber_IsFloatNumberGreater(const num1[], const num2[])
    - This native will compare two floating point numbers.

 - BigNumber_AddIntNumber(const num1[], const num2[], output[], len = sizeof(output))
    - This native will add two int number.

 - BigNumber_FormatIntNumber(const number[], const delimiter[] = ",", output[], len = sizeof(output))
    - This native will format whole number (separate with delimiter)

 - bool:BigNumber_IsIntNumberGreater(const num1[], const num2[])
    - This native will compare two whole numbers.

#### custom functions

 - BigNumber_AddNumber(const num1[], const num2[], bool:isFloat)
    - This function will add two passed value and check if the **isFloat** parameter is set to true then it will use **BigNumber_AddFloatNumber** otherwise **BigNumber_AddIntNumber**.

 - BigNumber_FormatNumber(const number[], const delimiter[] = ",", bool:isFloat)
    - This function will format passed value and check if the **isFloat** parameter is set to true then it will use **BigNumber_FormatFloatNumber** otherwise **BigNumber_FormatIntNumber**

 - bool:BigNumber_IsGreater(const num1[], const num2[], bool:isFloat)
    - This function will compare two passed value and check if the **isFloat** parameter is set to true then it will use **BigNumber_IsFloatNumberGreater** otherwise **BigNumber_IsIntNumberGreater**