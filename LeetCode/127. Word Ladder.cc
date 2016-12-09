class Solution {
public:
    int diff(string& s, string& t)
    {
        int diffCount = 0;
        int length = s.size();
        for(int i = 0; i < length; i ++)
        {
            if(s[i] != t[i])
            {
                diffCount ++;
            }
        }

        return diffCount;
    }

    int bfs(unordered_map<int, vector<int> >& graph, int startNode, int endNode, int totalNodes, bool *visited)
    {
        queue<int> q[2];
        int depth = 0;

        queue<int>*current = &q[0], *next = &q[1];
        visited[startNode] = true;
        current->push(startNode);

        while(current->empty() == false)
        {
            int front = current->front();
            if(words[front].compare(words[endNode]) == 0)
            {
                return depth;
            }

            unordered_map<int, vector<int> >::iterator itr = graph.find(front);

            if(itr != graph.end())
            {
                vector<int>::iterator end = itr->second.end();
                for(vector<int>::iterator i = itr->second.begin(); i != end; i++)
                {
                    if(visited[*i] == false)
                    {
                        visited[*i] = true;
                        next->push(*i);
                    }
                }
            }

            current->pop();
            if(current->empty())
            {
                if(current == &q[0])
                {
                    current = &q[1];
                    next = &q[0];
                }
                else
                {
                    current = &q[0];
                    next = &q[1];
                }

                depth++;
            }
        }

        return -1;
    }
    vector<string> words;
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_map<int, vector<int> > graph;
        bool visited[wordList.size() + 2] = {0};

        words.push_back(beginWord);
        words.push_back(endWord);
        int index = 2;
        for(unordered_set<string>::iterator itr = wordList.begin(); itr != wordList.end(); itr ++)
        {
            words.push_back(*itr);
            index ++;
        }

        int length = words.size();
        for(int i = 0; i < length; i++)
        {
            for(int j = i + 1; j < length; j ++)
            {
                string& currentWord = words[i];
                if(diff(words[i], words[j]) != 1)
                {
                    continue;
                }

                if(i == 0 && j == 1)
                {
                    continue;
                }
                
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

        int transformationLength = bfs(graph, 0, 1, length, visited);

        return transformationLength + 1;
    }
};