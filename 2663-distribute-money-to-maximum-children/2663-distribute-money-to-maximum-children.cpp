class Solution {
public:
   int distMoney(int money, int children) {
        if(children>money) return -1;
        int remainmoney=money-children;
        if(remainmoney<=6) return 0;  
        
      int ans=0;
        
      ans+=remainmoney/7;                            
	  
      if(ans>=children) ans=children;              
      
        if(remainmoney%7==3 and children-ans==1) return ans-1; 
        else if(remainmoney/7>children and children-ans==0) return ans-1;
        else if(remainmoney%7>0 and children-ans==0) return ans-1;
        else return ans;
    }
};