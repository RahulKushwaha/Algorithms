class Solution {
public:
    string simplifyPath(string path) {
        string str;
        if(path.size() > 0)
        {
            if(path[path.size() - 1] != '/')
            {
                path += "/";
            }
        }
        
        stack<string> reducedPath;
        for(int i = 0; i < path.size(); i ++)
        {
            if(path[i] == '/')
            {
                if(str.size() != 0)
                {
                    if(str.compare(".") == 0)
                    {
                        
                    }
                    else if(str.compare("..") == 0)
                    {
                        if(reducedPath.empty() == 0)
                        {
                            reducedPath.pop();
                        }
                    }
                    else
                    {
                        reducedPath.push(str);
                    }
                }
                
                str.clear();
            }
            else
            {
                str += path[i];
            }
        }
        
        str.clear();
        
        while(reducedPath.empty() == false)
        {
            string top  = reducedPath.top();
            str = top + "/" + str;
            reducedPath.pop();
        }

        if(str.size() == 0)
        {
            str += "/";
        }
        else{
            str.erase(str.size() - 1, 1);
            str = "/" + str;
        }
        
        return str;
    }
};