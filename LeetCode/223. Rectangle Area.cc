class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(E < A)
        {
            swap(A, E);
            swap(B, F);
            swap(C, G);
            swap(D, H);
        }
        
        int area1 = (D - B) * (C - A);
        int area2 = (H - F) * (G - E);
        
        int area = area1 + area2;
        
        if(!(A >= G || B >= H || C <= E || D <= F))
        {
            int height3 = abs(min(D, H) - max(B, F));
            int base3 = abs(min(C, G) - max(A, E));
            
            int area3 = height3 * base3;
            
            area = area - area3;
        }
        
        return area;
    }
};