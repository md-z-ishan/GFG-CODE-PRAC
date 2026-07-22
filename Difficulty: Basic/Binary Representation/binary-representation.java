class Solution {
    public String getBinaryRep(int n) {
        // code here
        String s=String.format("%32s",Integer.toBinaryString(n)).replace(' ','0');
        return s;
    }
    
        
    
}