class Solution {
public:
    bool isIsomorphic(string &s, string &t) 
    {
        // We can solve this question very easily with the help of Map or Unordered-Map
        // To improve our Space Complexity to O(1), we need to use vector of chars to map accordingly

        int n = s.size() ;

        // Initally, we will check if the element and element of S is mapped with T or not. If yes, if the mapping is not correct, we will return false ;

        vector<char> mapS(257 , ' ') ;
        vector<char> mapT(257 , ' ') ;

        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i] ;
            int index = (int) ch ;

            if(mapS[index] == ' ')
                mapS[index] = t[i] ;

            else if(mapS[index] != t[i])
                return false ;
     
            mapS[index] = t[i] ;
        }

        for(int i = 0 ; i < n ; i++)
        {
            char ch = t[i] ;
            int index = (int) ch ;

            if(mapT[index] == ' ')
                mapT[index] = s[i] ;

            else if(mapT[index] != s[i])
                return false ;            
            
            mapT[index] = s[i] ;

        }   
        
        // At the end, we will check for the very last time if all the mappings are valid or not
        for(int i = 0 ; i < 257 ; i++)
        {
            // If either of them is NULL(indicated by WhiteSpace), we move to next iteration
            if(mapS[i] == ' ' || mapT[i] == ' ')
                continue ;

            // ChS = i-th index converted to Character
            char chS = (char) i ;

            // Map_Of_S is the character stored in MapS[i]
            char map_of_S = mapS[i] ;

            // We need to cross verify that all the Mappings are correct or not

            // We store the Index of Map_Of_S 
            int index = (int) map_of_S ;

            // Using that index, we get Map_Of_T
            char chT = (int) index ;
            char map_of_T = mapT[index] ;

            // We get ChT from Map_Of_S only so this check is pretty useless
            // if( (map_of_S == chT) && (map_of_T == chS) ) 
            //     continue ;

            // If Map_Of_T and ChS are equal, it means the mapping is correct
            if(map_of_T == chS)
                continue ;

            // Otherwise we return false
            return false ;
        }

        // At the end, if all checks are done, then they are Isomporhic Strings
        return true ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1) [ As we are only using two arrays of size 257, which is, independent of N]
