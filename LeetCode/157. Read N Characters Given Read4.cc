// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    char *internalBuffer;
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int length = 0;
        int index = 0, limit = 0;
        char internalBuffer[4];
        char * buffer = &internalBuffer[index];
        while(n > length)
        {
            if(index == limit)
            {
                buffer = internalBuffer;
                limit = read4(internalBuffer);
                index = 0;
                
                if(limit == index)
                {
                    break;
                }
            }
            
            int copyLength = min(n - length, limit - index);
            memcpy(buf, buffer, copyLength);
            
            buf += copyLength;
            index += copyLength;
            length += copyLength;
            buffer += copyLength;
        }
        
        return length;
    }
};