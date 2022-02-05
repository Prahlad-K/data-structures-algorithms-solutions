#include <iostream>
#include <cstring>

using namespace std;

struct trnode{
    int flag;
    int pos;
    union u{
        char str[50];
        struct trnode *ptr[27];
    }data;
    struct trnode* pptr;
};

typedef trnode *trptr;

void assign(string str, char string2[]){
    for(int i = 0 ; i < str.length() ; i++){
        string2[i] = str[i];
    }
}

trptr find(trptr t, string key){
    int l = 0;
    if(t != NULL){
        while(t->flag != 0){
            l = t->pos;
            if(t->data.ptr[26] != NULL){
                if(t->data.ptr[26]->data.str == key)
                    return t->data.ptr[26];
            }
            if(t->data.ptr[(int)key[l]-97] == NULL || l == key.length()){
                return NULL;
            }
            else{
                t = t->data.ptr[(int)key[l]-97]; l++;
            }
        }
        if(t->data.str == key)
            return t;
        else
            return NULL;
    }
    return NULL;
}

int common(string str, string key){
    int l1 = str.length();
    int l2 = key.length();
    int min = l1 < l2? l1 : l2;
    for(int i = 0 ; i < min ; i++){
        if(str[i] != key[i])
            return i;
    }
    return min;
}

string findstr(trptr t){
    if(t->flag == 0){
        return t->data.str;
    }
    else{
        for(int i = 0 ; i < 26 ; i++){
            if(t->data.ptr[i] != NULL){
                return findstr(t->data.ptr[i]);
            }
        }
        string ans = "";
        return ans;
    }
}

trptr insert(trptr t, string key, int idx){
    trptr tmp = find(t, key);
    if(tmp != NULL){
        cout << "Key already inserted\n";
        return t;
    }
    else{
        trptr head = t;
        if(t == NULL){
            cout << "COND1" << key << endl;
            t = new(trnode);
            t->flag = 0;
            t->pos = idx;
            assign(key, t->data.str);
            return t;
        }

        else if(t->flag == 1){
            cout << "COND2" << key << endl;
            string ins = findstr(t);
            if(ins != ""){
                cout << "COND3" << key << endl;
                int com = common(ins, key);
                if(com >= t->pos){
                    cout << "COND4" << key << endl;
                    t->data.ptr[(int)key[t->pos]-97] = insert(t->data.ptr[(int)key[t->pos]-97], key, t->pos+1);
                }
                else{
                    cout << "COND5" << key << com << t->pos << endl;
                    head = new(trnode);
                    head->flag = 1;
                    head->pos = com;
                    head = insert(head, key, com+1);
                    head->data.ptr[(int)ins[com]-97] = t;
                    t = head;
                }
            }
            else{
                cout << "COND6" << key << endl;
                t->data.ptr[(int)key[t->pos]-97] = insert(t->data.ptr[(int)key[t->pos]-97], key, t->pos+1);
            }
            return t;
        }
        else if(t->flag == 0){
            cout << "COND7" << key << endl;
            trptr nd = new(trnode);
            string str = t->data.str;
            nd->flag = 1;

            int com = common(str, key);
            nd->pos = com;

            nd = insert(nd, key, nd->pos);
            nd = insert(nd, str, nd->pos);

            return nd;
        }
    }
}

void print(trptr t, int gap){
    if(t != NULL){
        if(t->flag == 0){
            int n = gap;
            while(n--) cout << "\t";
            cout << "String: " << t->data.str << "  pos: " << t->pos << endl;
        }
        if(t->flag == 1){
            for(int i = 0 ; i < 27; i++){
                if(t->data.ptr[i] != NULL){
                    int n = gap; int n2 = gap;
                    while(n--) cout << "\t";
                    cout << "pos: " << t->pos << endl;
                    while(n2--) cout << "\t";
                    if(i != 26)
                        cout << (char)(i + 97) << endl;
                    else
                        cout << "*" << endl;
                    print(t->data.ptr[i], gap+1);
                }
            }
        }
    }
}

int main(){
    string str = "";
    trptr t = NULL;
    while(str != "stop"){
        cout << "Enter word to insert into trie(enter stop to stop): ";
        cin >> str;
        t = insert(t, str, 0);
        print(t, 1);
    }

    str = "";
    while(str != "stop"){
        cout << "Enter word to find in trie(enter stop to stop): ";
        cin >> str;
        trptr tmp = find(t, str);
        if(tmp != NULL)
            cout << "yes";
        else
            cout << "no";
    }

    print(t, 1);

    return 0;
}
