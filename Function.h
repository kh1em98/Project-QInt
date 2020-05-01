﻿// Các hàm hỗ trợ

#ifndef _FUNCTION_H
#define _FUNCTION_H
#endif
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Hàm đảo ngược chuỗi
void reverseStr(string& str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

// Biến chuỗi nhị phân thành 1 số nguyên
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0 
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

// Kiểm tra giá trị str1 có nhỏ hơn giá trị str2 hay ko
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}


// Hàm trừ 2 string, 2 str ko phải số âm
string TruHaiChuoiKhongXetDau(string str1, string str2)
{
    bool negative = false;
    // Nếu str1 nhỏ hơn str2, ta cần swap 
    if (isSmaller(str1, str2))
    {
        swap(str1, str2);
        negative = true;
    }


    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    // Đảo ngược 2 str để phục vụ phép trừ
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    for (int i = 0; i < n2; i++)
    {

        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());

    if (negative)
    {
        str = '-' + str;
    }

    return str;
}

// Cộng hai chuỗi 
string CongHaiChuoi(string str1, string str2)
{
    bool negative = false; 
    if (str1[0] == '-' && str2[0] == '-')
    {
        str1.erase(str1.begin());
        str2.erase(str2.begin());
        negative = true;
    }
    else if (str1[0] == '-' && str2[0] != '-')
    {
        str1.erase(str1.begin());
        return TruHaiChuoiKhongXetDau(str2, str1);
    }
    else if (str1[0] != '-' && str2[0] == '-')
    {
        str2.erase(str2.begin());
        return TruHaiChuoiKhongXetDau(str1, str2);
    }

    // Đảm bảo str2 có độ dài lớn hơn hoặc bằng str1
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    { 
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

    reverse(str.begin(), str.end());

    if (negative)
    {
        str = '-' + str;
    }

    return str;
}



// Trừ hai chuỗi
string TruHaiChuoi(string str1, string str2)
{
    if (str1[0] == '-' && str2[0] == '-')
    {
        str1.erase(str1.begin());
        str2.erase(str2.begin());
        return TruHaiChuoi(str2, str1);
    }
    else if (str1[0] == '-' && str2[0] != '-')
    {
        str1.erase(str1.begin());
        return CongHaiChuoi(str2, str1);
    }
    else if (str1[0] != '-' && str2[0] == '-')
    {
        str2.erase(str2.begin());
        return CongHaiChuoi(str1, str2);
    }

    bool negative = false; 
    // Nếu str1 nhỏ hơn str2, ta cần swap 
    if (isSmaller(str1, str2))
    {
        swap(str1, str2);
        negative = true; 

    }


    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    // Đảo ngược 2 str để phục vụ phép trừ
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    for (int i = 0; i < n2; i++)
    {

        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());

    if (negative)
    {
        str = '-' + str;
    }

    return str;
}


// Nhân hai chuỗi
string NhanHaiChuoi(string s1, string s2)
{
    bool negative = false; 

    if (s1[0] == '-' && s2[0] == '-')
    {
        s1.erase(s1.begin());
        s2.erase(s2.begin());
    }
    else if (s1[0] == '-' || s2[0] == '-')
    {
        negative = true; 
        if (s1[0] == '-')
        {
            s1.erase(s1.begin());
        }
        else
        {
            s2.erase(s2.begin());
        }
    }


    int len1 = s1.size();
    int len2 = s2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    
    // Khởi tạo vector chứa các int với size = len1 + len2, giá trị khởi tạo = 0 
    vector<int> result(len1 + len2, 0);

    // Các biến dùng để xác định vị trí phép cộng nằm ở hàng đơn vị, chục, trăm...
    int i_n1 = 0;
    int i_n2 = 0;


    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;

        // Lấy giá trị dạng int trong chuỗi
        int n1 = s1[i] - '0';

        i_n2 = 0;
           
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = s2[j] - '0';

            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            // Phần nhớ
            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // Nếu sau khi nhân 1 số vs tất cả các chữ số mà vẫn còn phần nhớ, ta cần cộng thêm vào phần hiện tại
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    // Kêt quả được lưu vào vector theo dạng đảo ngược, ví dụ = 200 thì res[0] = 0, res[1] = 0, res[2] = 2 -> cần xoá phần thừa nằm bên phải
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    // Nếu tất cả các số đều = 0 -> có nghĩa s1 hoặc s2 = 0
    if (i == -1)
        return "0";

    string s = "";

    // Tạo hàm string lưu kết quả tính được
    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}


// Tính 2^n
string LuyThua2(int n)
{
    string result;
    
    // Nếu n lớn hơn 31 có khả năng tràn số uint32_t
    if (n > 31)
    {
        result = to_string((uint32_t)pow(2, 31));

        // Phần còn lại ta sẽ nhân chuỗi kết quả với 2 liên tục cho tới khi đủ n
        for (int i = 32; i <= n; i++)
        {
            result = NhanHaiChuoi(result, "2");
        }
    }
    else
    {
        result = to_string((uint32_t)pow(2, n));
    }

    return result; 

}
