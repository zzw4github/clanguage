/*
5、注意指针的释放问题，可能形成悬浮指针。 
   当我们释放掉一个指针p后，只是告诉操作系统该段内存可以被其他程序使用，
   而该指针p的地址值(如ox23)仍然存在。如果再次给这块地址赋值是危险的，应该将p指针置为NULL。 
   调用函数删除主函数中的内存块时，虽然可以通过地址传递直接删除，
   但由于无法对该指针赋值(形参不能传值)，可能造成悬浮指针，
   所以此时也应该采用指向指针的指针的形参。例如： 
*/
            void MemoryFree(char** p) 
            { 
                delete *p; 
                *p = NULL; 
            } 
            void main() 
            { 
                char* str = new char[100]; 
                char* pstr = &str; 
                MemoryFree(pstr); 
            } 