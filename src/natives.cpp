#include "sdk.hpp"
#include "natives.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

string _BigNumber_AddFloatNumber(string currentNumber, string value)
{
    double currentNum = stod(currentNumber);
    double val = stod(value);

    double sum = currentNum + val;

    ostringstream oss;
    oss << fixed << setprecision(16) << sum;
    string str = oss.str();

    str.erase(str.find_last_not_of('0') + 1, string::npos);

    return str;
}

string _BigNumber_FormatFloatNumber(string number, string delimiter = ",")
{
    size_t decimalPos = number.find(".");
    string wholePart = number.substr(0, decimalPos);

    int length = wholePart.length();
    int insertPosition = (length > 3) ? length % 3 : 0;

    string formattedNumber;
    for (int i = 0; i < length; ++ i)
    {
        if (i != 0 && i % 3 == insertPosition)
        {
            formattedNumber += delimiter;
        }
        formattedNumber += wholePart[i];
    }

    if (decimalPos != string::npos)
    {
        string decimalPart = number.substr(decimalPos + 1);
        formattedNumber += "." + decimalPart;
    }
    
    return formattedNumber;
}

bool _BigNumber_IsFloatNumberGreater(string num1, string num2)
{
    return stod(num1) > stod(num2);
}

string _BigNumber_AddIntNumber(string currentNumber, string value)
{
    long long int currentNum = stoll(currentNumber);
    long long int val = stoll(value);

    long long int sum = currentNum + val;

    ostringstream oss;
    oss << sum;

    return oss.str();
}

string _BigNumber_FormatIntNumber(string number, string delimiter = ",")
{
    int length = number.length();
    int insertPosition = (length > 3) ? length % 3 : 0;

    string formattedNumber;

    for (int i = 0; i < length; ++ i)
    {
        if (i != 0 && i % 3 == insertPosition)
        {
            formattedNumber += delimiter;
        }
        formattedNumber += number[i];
    }

    return formattedNumber;
}

bool _BigNumber_IsIntNumberGreater(string num1, string num2)
{
    return stoll(num1) > stoll(num2);
}

// native BigNumber_AddFloatNumber(const num1[], const num2[], output[], len = sizeof(output));
AMX_DECLARE_NATIVE(Native::BigNumber_AddFloatNumber)
{
    string num1 = amx_GetCppString(amx, params[1]);
    string num2 = amx_GetCppString(amx, params[2]);

    amx_SetCppString(amx, params[3], _BigNumber_AddFloatNumber(num1, num2), params[4]);
    return 1;
}

// native BigNumber_FormatFloatNumber(const number[], const delimiter[] = ",", output[], len = sizeof(output));
AMX_DECLARE_NATIVE(Native::BigNumber_FormatFloatNumber)
{
    string number = amx_GetCppString(amx, params[1]);
    string delimiter = amx_GetCppString(amx, params[2]);

    amx_SetCppString(amx, params[3], _BigNumber_FormatFloatNumber(number, delimiter), params[4]);
    return 1;
}

// native bool:BigNumber_IsFloatNumberGreater(const num1[], const num2[]);
AMX_DECLARE_NATIVE(Native::BigNumber_IsFloatNumberGreater)
{
    string num1 = amx_GetCppString(amx, params[1]);
    string num2 = amx_GetCppString(amx, params[2]);

    if (_BigNumber_IsFloatNumberGreater(num1, num2))
    {
        return true;
    }

    return false;
}

// native BigNumber_AddIntNumber(const num1[], const num2[], output[], len = sizeof(output));
AMX_DECLARE_NATIVE(Native::BigNumber_AddIntNumber)
{
    string num1 = amx_GetCppString(amx, params[1]);
    string num2 = amx_GetCppString(amx, params[2]);

    amx_SetCppString(amx, params[3], _BigNumber_AddIntNumber(num1, num2), params[4]);
    return 1;
}

// native BigNumber_FormatIntNumber(const number[], const delimiter[] = ",", output[], len = sizeof(output));
AMX_DECLARE_NATIVE(Native::BigNumber_FormatIntNumber)
{
    string number = amx_GetCppString(amx, params[1]);
    string delimiter = amx_GetCppString(amx, params[2]);

    amx_SetCppString(amx, params[3], _BigNumber_FormatIntNumber(number, delimiter), params[4]);
    return 1;
}

// native bool:BigNumber_IsIntNumberGreater(const num1[], const num2[])
AMX_DECLARE_NATIVE(Native::BigNumber_IsIntNumberGreater)
{
    string num1 = amx_GetCppString(amx, params[1]);
    string num2 = amx_GetCppString(amx, params[2]);

    if (_BigNumber_IsIntNumberGreater(num1, num2))
    {
        return true;
    }
    
    return false;
}