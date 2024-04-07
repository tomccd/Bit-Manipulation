#include <iostream>
#include <bitset>

class bitManipulation{
    public:
    int getBitinNth(std::bitset <8> bitNum,int n){
        if(n>=8 || n<0){
            throw std::invalid_argument("Invalid input");
        }
        else{
            /*Xóa hết tất cả các bit trừ bit thứ n*/
            std::bitset <8> mask = (1<<n);
            /*And với mask*/
            bitNum = bitNum&mask;
            return (int)(bitNum>>n).to_ulong();
        }
    }
    std::bitset<8> setBit(std::bitset<8> bitNum,int n){
        if(n>=8 || n<0){
            throw std::invalid_argument("Invalid input");
        }
        else{
            std::bitset <8> mask = (1<<n);
            /*OR với mask -> set bit thứ n lên 1*/
            return bitNum|mask;
        }
    }
    std::bitset<8> clearBit(std::bitset<8> bitNum,int n){
        if(n>=8 || n<0){
            throw std::invalid_argument("Invalid input");
        }
        else{
            std::bitset <8> mask = ~(1<<n);
            /*OR với mask -> set bit thứ n lên 1*/
            return bitNum&mask;
        }
    }
    std::bitset<8> updateBit(std::bitset<8> bitNum,int n,int value){
        if(n>=8 || n<0){
            throw std::invalid_argument("Invalid input");
        }
        else{
            /*Nếu value > 0 -> set = 1 nếu không thì set = 0*/
            value  = value?1:0;
            /*Xóa bit thứ n */
            std::bitset<8> mask = ~(1<<n);
            return (mask&bitNum)|std::bitset<8>(value<<n);
        }
    }    
};

int main(){
    bitManipulation handle;
    std::bitset<8> a = 0b00001000;
    std::cout<<handle.getBitinNth(a,3) << std::endl;
    // std::cout<<handle.setBit(a,6) << std::endl;
    // std::cout<<handle.clearBit(a,6) << std::endl;
    // std::cout<<handle.updateBit(a,6,1);
}