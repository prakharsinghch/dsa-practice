class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans=0;
        int z=0;
        while(mainTank--){
            ans+=10;
            z++;
            if(z==5){
                z=0;
                if(additionalTank){
                    additionalTank--;
                    mainTank++;
                }
            }
        }
       
        
        return ans;
        
    }
};