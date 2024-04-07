#include <iostream>
#include <bitset>
#include <math.h>
class solution{
    public:
    std::bitset<32> shiftBit(std::bitset<32> M, std::bitset<32> N, int i,int j){
        if(i<=j){
            throw std::invalid_argument("Invalid Value");
        }
        else{
            /*Nếu kích thước từ i đến j không đủ cho N*/
            if(pow(2,i-j+1)-1<(int)M.to_ulong()){
                //std::cout << (int)N.to_ulong();
                throw std::invalid_argument("Invalid Value");
            }
            else{
                /*1. Clear the bits j through i in N*/
                //Tính giá trị bit từ i -> j : 2^(9-5+1) = 31 = 0b11111
                int shiftValue = pow(2,i-j+1)-1;
                //Shift bit đến index j -> 0b 1 1111 000
                //Tạo mask chứa các bit xóa
                std::bitset<32> mask = std::bitset<32>(shiftValue);
                while(mask.to_ulong()<= pow(2,i)-1){
                    mask = mask<<1;
                }
                mask = mask>>1;
                //đảo bit trong mask 
                mask = ~mask;
                // std::cout << N << std::endl;
                // std::cout << mask << std::endl;
                //std::cout << mask;
                //Clear the bit from i -> j in N
                N = N&mask;
                // std::cout << N << std::endl;
                /*2. Shift M so that it lines up with bits j through i*/
                while(M.to_ulong()<= pow(2,i)-1){
                    M = M<<1;
                }
                //Shift right 1 because of loop
                M = M>>1;
                /*3. Merge M and N*/
                return M|N;
            }
            return 0;
        }
    }
};

int main(){
    solution slt;
    std::bitset<32>N = 0b1000000000;
    std::bitset<32>M = 0b10011;
    std::cout<<slt.shiftBit(M,N,6,2);
}