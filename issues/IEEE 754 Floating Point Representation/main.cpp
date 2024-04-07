/*IEE 754 Floating Point Representation (float -> 32 bit binary)
        *                     ********            ***********************
   (1 signed bit          (8 bits exponent)       (23 bits fraction bit)
    bit quy định dấu)
*/
#include <iostream>
#include <bitset>
#include <math.h>
int exponentOfInt2Binary(int number){
    int count = 0;
    while(number!=0){
        number = number/2;
        count+=1;
    }
    return count;
}
int getBitInNth(int number,int n){
    int mask = (1<<n);
    return ((number&mask)>>n);
}
int deleleBit(int number ,int index){
    return number&(~(1<<index));
}
std::bitset<32> IEE754_Float_Representation(float number){
    //Tách phần nguyên cho vào kết quả
    float copy_num = number;
    if(number < 0){
        copy_num = copy_num*(-1.0);
    }
    // Tìm số mũ trong binary của phần nguyên
    int exponentOfInt = exponentOfInt2Binary(int(copy_num));
    // Tìm phần thập phân
    float frac = copy_num - int(copy_num);
    int result_frac = 0;
    int count = 0;
    //Tính toán : phân tách phần số nguyên thành số nhị phân (với độ chính xác là 23 bit)
    while(count<23){
        frac*=2;
        result_frac = result_frac | int(frac)<<(22-count);
        frac = frac - int(frac);
        count+=1;
    }
    count = 0;
    /*Đẩy phần số thập phần (dạng nhị phân) sang phải để thêm các bit ở phần số nguyên (dạng nhị phân) cho đến khi bằng số mũ của phần số nguyên -1*/
    while(count<=exponentOfInt-1){
        result_frac = (result_frac>>1) | (getBitInNth(int(copy_num),count)<<22);
        count++;
    }
    //Reset bit đầu tiên của phần kết quả đồng thời dồn bit sang phải 1 bit để tượng trưng cho việc xóa bit
    int second_result = deleleBit(result_frac,22)<<1;
// Xác định phần bit số mũ (exponent) và phần bit xác định âm dương (signed bit)
  int exponent = 127;
  int signedBit = 1;
  if(number>0){
    exponent = exponent+exponentOfInt-1;
    signedBit = 0;
  }
  else if(number<0){
    exponent = exponent+exponentOfInt-1;
    signedBit = 1;
  }
  else{
    exponent = 0;
    signedBit = 0;
  }
  //Đẩy phần bit của phần số mũ sang trái 23 bit (vị trí bắt đầu của phần bit số mũ)
  exponent = exponent << 23;
  /*Đẩy phần bit của phần bit xác định âm dương 
  sang trái 31 bit (vị trí bắt đầu của phần bit xác định ấm dương)*/
  signedBit = signedBit << 31;
  /*OR 3 phần nhị phân lại với nhau để ra kết quả theo chuẩn IEE654*/
  return signedBit|exponent|second_result;
}

int main(){
    std::cout << IEE754_Float_Representation(-1631553123.5);
}

