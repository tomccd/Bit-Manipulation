#include <iostream>
#include <bitset>

int getBitInNth(std::bitset <8>binaryInput,int n){
    if(n>=8 || n<0){
        throw std::invalid_argument("Invalid Argument");
    }
    else{
        std::bitset <8> mask = (1<<n);
        return int(((binaryInput&mask)>>n).to_ulong());
    }
}

int count1Bit(std::bitset<8> binaryInput){
    int count = 0;
    for(int i=0;i<8;i++){
        if(getBitInNth(binaryInput,i) == 1){
            count++;
        }
    }
    return count;
}

int main(){
    std::bitset<8> input = 0b00011000;
    std::cout<< count1Bit(input);
}