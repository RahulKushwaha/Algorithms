class Solution {
public:
    int maxRotateFunction(vector<int>& elements) {
        int length = elements.size();
        
        int sum = 0;
        int weightedSum = 0;
        for(int i = 0; i < length; i ++)
        {
            sum += elements[i];
            weightedSum += i * elements[i]; 
        }
        
        int output = weightedSum;
        for(int i = length - 1; i >= 0; i --)
        {
            weightedSum += sum;
            weightedSum -= length * elements[i];
            
            output = max(output, weightedSum);
        }
        
        return output;
    }
};