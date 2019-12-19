#include <iostream>

using namespace std;

const int N = 2058;

int biao[N][3] = {
    {0, 2, 21}, {0, 5, 1}, {0, 8, 21}, {0, 9, 11}, {0, 12, 11}, {1, 1, 1}, {1, 5, 21}, {1, 6, 11}, {1, 10, 1}, {2, 1, 21}, 
    {2, 2, 11}, {2, 3, 11}, {2, 4, 1}, {2, 7, 1}, {2, 10, 21}, {2, 11, 11}, {3, 4, 21}, {3, 7, 21}, {3, 8, 11}, {3, 9, 1}, 
    {3, 12, 1}, {4, 3, 1}, {4, 6, 21}, {4, 10, 11}, {4, 11, 1}, {5, 2, 21}, {5, 3, 21}, {5, 4, 11}, {5, 7, 11}, {5, 8, 1}, 
    {5, 11, 21}, {6, 5, 1}, {6, 8, 21}, {6, 9, 11}, {6, 12, 11}, {7, 1, 1}, {7, 5, 21}, {7, 6, 11}, {7, 10, 1}, {8, 1, 21}, 
    {8, 2, 11}, {8, 4, 21}, {8, 7, 21}, {8, 8, 11}, {8, 9, 1}, {8, 12, 1}, {9, 5, 11}, {9, 6, 1}, {9, 9, 21}, {9, 12, 21}, 
    {10, 1, 11}, {10, 2, 1}, {10, 3, 1}, {10, 6, 21}, {10, 10, 11}, {10, 11, 1}, {11, 2, 21}, {11, 3, 21}, {11, 4, 11}, {11, 7, 11}, 
    {11, 8, 1}, {11, 11, 21}, {12, 5, 21}, {12, 6, 11}, {12, 10, 1}, {13, 1, 21}, {13, 2, 11}, {13, 3, 11}, {13, 4, 1}, {13, 7, 1}, 
    {13, 10, 21}, {13, 11, 11}, {14, 4, 21}, {14, 7, 21}, {14, 8, 11}, {14, 9, 1}, {14, 12, 1}, {15, 5, 11}, {15, 6, 1}, {15, 9, 21}, 
    {15, 12, 21}, {16, 1, 11}, {16, 2, 1}, {16, 3, 21}, {16, 4, 11}, {16, 7, 11}, {16, 8, 1}, {16, 11, 21}, {17, 5, 1}, {17, 8, 21}, 
    {17, 9, 11}, {17, 12, 11}, {18, 1, 1}, {18, 5, 21}, {18, 6, 11}, {18, 10, 1}, {19, 1, 21}, {19, 2, 11}, {19, 3, 11}, {19, 4, 1}, 
    {19, 7, 1}, {19, 10, 21}, {19, 11, 11}, {20, 5, 11}, {20, 6, 1}, {20, 9, 21}, {20, 12, 21}, {21, 1, 11}, {21, 2, 1}, {21, 3, 1}, 
    {21, 6, 21}, {21, 10, 11}, {21, 11, 1}, {22, 2, 21}, {22, 3, 21}, {22, 4, 11}, {22, 7, 11}, {22, 8, 1}, {22, 11, 21}, {23, 5, 1}, 
    {23, 8, 21}, {23, 9, 11}, {23, 12, 11}, {24, 1, 1}, {24, 3, 11}, {24, 4, 1}, {24, 7, 1}, {24, 10, 21}, {24, 11, 11}, {25, 4, 21}, 
    {25, 7, 21}, {25, 8, 11}, {25, 9, 1}, {25, 12, 1}, {26, 5, 11}, {26, 6, 1}, {26, 9, 21}, {26, 12, 21}, {27, 1, 11}, {27, 2, 1}, 
    {27, 3, 1}, {27, 6, 21}, {27, 10, 11}, {27, 11, 1}, {28, 2, 21}, {28, 5, 1}, {28, 8, 21}, {28, 9, 11}, {28, 12, 11}, {29, 1, 1}, 
    {29, 5, 21}, {29, 6, 11}, {29, 10, 1}, {30, 1, 21}, {30, 2, 11}, {30, 3, 11}, {30, 4, 1}, {30, 7, 1}, {30, 10, 21}, {30, 11, 11}, 
    {31, 4, 21}, {31, 7, 21}, {31, 8, 11}, {31, 9, 1}, {31, 12, 1}, {32, 3, 1}, {32, 6, 21}, {32, 10, 11}, {32, 11, 1}, {33, 2, 21}, 
    {33, 3, 21}, {33, 4, 11}, {33, 7, 11}, {33, 8, 1}, {33, 11, 21}, {34, 5, 1}, {34, 8, 21}, {34, 9, 11}, {34, 12, 11}, {35, 1, 1}, 
    {35, 5, 21}, {35, 6, 11}, {35, 10, 1}, {36, 1, 21}, {36, 2, 11}, {36, 4, 21}, {36, 7, 21}, {36, 8, 11}, {36, 9, 1}, {36, 12, 1}, 
    {37, 5, 11}, {37, 6, 1}, {37, 9, 21}, {37, 12, 21}, {38, 1, 11}, {38, 2, 1}, {38, 3, 1}, {38, 6, 21}, {38, 10, 11}, {38, 11, 1}, 
    {39, 2, 21}, {39, 3, 21}, {39, 4, 11}, {39, 7, 11}, {39, 8, 1}, {39, 11, 21}, {40, 5, 21}, {40, 6, 11}, {40, 10, 1}, {41, 1, 21}, 
    {41, 2, 11}, {41, 3, 11}, {41, 4, 1}, {41, 7, 1}, {41, 10, 21}, {41, 11, 11}, {42, 4, 21}, {42, 7, 21}, {42, 8, 11}, {42, 9, 1}, 
    {42, 12, 1}, {43, 5, 11}, {43, 6, 1}, {43, 9, 21}, {43, 12, 21}, {44, 1, 11}, {44, 2, 1}, {44, 3, 21}, {44, 4, 11}, {44, 7, 11}, 
    {44, 8, 1}, {44, 11, 21}, {45, 5, 1}, {45, 8, 21}, {45, 9, 11}, {45, 12, 11}, {46, 1, 1}, {46, 5, 21}, {46, 6, 11}, {46, 10, 1}, 
    {47, 1, 21}, {47, 2, 11}, {47, 3, 11}, {47, 4, 1}, {47, 7, 1}, {47, 10, 21}, {47, 11, 11}, {48, 5, 11}, {48, 6, 1}, {48, 9, 21}, 
    {48, 12, 21}, {49, 1, 11}, {49, 2, 1}, {49, 3, 1}, {49, 6, 21}, {49, 10, 11}, {49, 11, 1}, {50, 2, 21}, {50, 3, 21}, {50, 4, 11}, 
    {50, 7, 11}, {50, 8, 1}, {50, 11, 21}, {51, 5, 1}, {51, 8, 21}, {51, 9, 11}, {51, 12, 11}, {52, 1, 1}, {52, 3, 11}, {52, 4, 1}, 
    {52, 7, 1}, {52, 10, 21}, {52, 11, 11}, {53, 4, 21}, {53, 7, 21}, {53, 8, 11}, {53, 9, 1}, {53, 12, 1}, {54, 5, 11}, {54, 6, 1}, 
    {54, 9, 21}, {54, 12, 21}, {55, 1, 11}, {55, 2, 1}, {55, 3, 1}, {55, 6, 21}, {55, 10, 11}, {55, 11, 1}, {56, 2, 21}, {56, 5, 1}, 
    {56, 8, 21}, {56, 9, 11}, {56, 12, 11}, {57, 1, 1}, {57, 5, 21}, {57, 6, 11}, {57, 10, 1}, {58, 1, 21}, {58, 2, 11}, {58, 3, 11}, 
    {58, 4, 1}, {58, 7, 1}, {58, 10, 21}, {58, 11, 11}, {59, 4, 21}, {59, 7, 21}, {59, 8, 11}, {59, 9, 1}, {59, 12, 1}, {60, 3, 1}, 
    {60, 6, 21}, {60, 10, 11}, {60, 11, 1}, {61, 2, 21}, {61, 3, 21}, {61, 4, 11}, {61, 7, 11}, {61, 8, 1}, {61, 11, 21}, {62, 5, 1}, 
    {62, 8, 21}, {62, 9, 11}, {62, 12, 11}, {63, 1, 1}, {63, 5, 21}, {63, 6, 11}, {63, 10, 1}, {64, 1, 21}, {64, 2, 11}, {64, 4, 21}, 
    {64, 7, 21}, {64, 8, 11}, {64, 9, 1}, {64, 12, 1}, {65, 5, 11}, {65, 6, 1}, {65, 9, 21}, {65, 12, 21}, {66, 1, 11}, {66, 2, 1}, 
    {66, 3, 1}, {66, 6, 21}, {66, 10, 11}, {66, 11, 1}, {67, 2, 21}, {67, 3, 21}, {67, 4, 11}, {67, 7, 11}, {67, 8, 1}, {67, 11, 21}, 
    {68, 5, 21}, {68, 6, 11}, {68, 10, 1}, {69, 1, 21}, {69, 2, 11}, {69, 3, 11}, {69, 4, 1}, {69, 7, 1}, {69, 10, 21}, {69, 11, 11}, 
    {70, 4, 21}, {70, 7, 21}, {70, 8, 11}, {70, 9, 1}, {70, 12, 1}, {71, 5, 11}, {71, 6, 1}, {71, 9, 21}, {71, 12, 21}, {72, 1, 11}, 
    {72, 2, 1}, {72, 3, 21}, {72, 4, 11}, {72, 7, 11}, {72, 8, 1}, {72, 11, 21}, {73, 5, 1}, {73, 8, 21}, {73, 9, 11}, {73, 12, 11}, 
    {74, 1, 1}, {74, 5, 21}, {74, 6, 11}, {74, 10, 1}, {75, 1, 21}, {75, 2, 11}, {75, 3, 11}, {75, 4, 1}, {75, 7, 1}, {75, 10, 21}, 
    {75, 11, 11}, {76, 5, 11}, {76, 6, 1}, {76, 9, 21}, {76, 12, 21}, {77, 1, 11}, {77, 2, 1}, {77, 3, 1}, {77, 6, 21}, {77, 10, 11}, 
    {77, 11, 1}, {78, 2, 21}, {78, 3, 21}, {78, 4, 11}, {78, 7, 11}, {78, 8, 1}, {78, 11, 21}, {79, 5, 1}, {79, 8, 21}, {79, 9, 11}, 
    {79, 12, 11}, {80, 1, 1}, {80, 3, 11}, {80, 4, 1}, {80, 7, 1}, {80, 10, 21}, {80, 11, 11}, {81, 4, 21}, {81, 7, 21}, {81, 8, 11}, 
    {81, 9, 1}, {81, 12, 1}, {82, 5, 11}, {82, 6, 1}, {82, 9, 21}, {82, 12, 21}, {83, 1, 11}, {83, 2, 1}, {83, 3, 1}, {83, 6, 21}, 
    {83, 10, 11}, {83, 11, 1}, {84, 2, 21}, {84, 5, 1}, {84, 8, 21}, {84, 9, 11}, {84, 12, 11}, {85, 1, 1}, {85, 5, 21}, {85, 6, 11}, 
    {85, 10, 1}, {86, 1, 21}, {86, 2, 11}, {86, 3, 11}, {86, 4, 1}, {86, 7, 1}, {86, 10, 21}, {86, 11, 11}, {87, 4, 21}, {87, 7, 21}, 
    {87, 8, 11}, {87, 9, 1}, {87, 12, 1}, {88, 3, 1}, {88, 6, 21}, {88, 10, 11}, {88, 11, 1}, {89, 2, 21}, {89, 3, 21}, {89, 4, 11}, 
    {89, 7, 11}, {89, 8, 1}, {89, 11, 21}, {90, 5, 1}, {90, 8, 21}, {90, 9, 11}, {90, 12, 11}, {91, 1, 1}, {91, 5, 21}, {91, 6, 11}, 
    {91, 10, 1}, {92, 1, 21}, {92, 2, 11}, {92, 4, 21}, {92, 7, 21}, {92, 8, 11}, {92, 9, 1}, {92, 12, 1}, {93, 5, 11}, {93, 6, 1}, 
    {93, 9, 21}, {93, 12, 21}, {94, 1, 11}, {94, 2, 1}, {94, 3, 1}, {94, 6, 21}, {94, 10, 11}, {94, 11, 1}, {95, 2, 21}, {95, 3, 21}, 
    {95, 4, 11}, {95, 7, 11}, {95, 8, 1}, {95, 11, 21}, {96, 5, 21}, {96, 6, 11}, {96, 10, 1}, {97, 1, 21}, {97, 2, 11}, {97, 3, 11}, 
    {97, 4, 1}, {97, 7, 1}, {97, 10, 21}, {97, 11, 11}, {98, 4, 21}, {98, 7, 21}, {98, 8, 11}, {98, 9, 1}, {98, 12, 1}, {99, 5, 11}, 
    {99, 6, 1}, {99, 9, 21}, {99, 12, 21}, {100, 1, 11}, {100, 2, 1}, {100, 3, 1}, {100, 6, 21}, {100, 10, 11}, {100, 11, 1}, {101, 2, 21}, 
    {101, 3, 21}, {101, 4, 11}, {101, 7, 11}, {101, 8, 1}, {101, 11, 21}, {102, 5, 1}, {102, 8, 21}, {102, 9, 11}, {102, 12, 11}, {103, 1, 1}, 
    {103, 5, 21}, {103, 6, 11}, {103, 10, 1}, {104, 1, 21}, {104, 2, 11}, {104, 4, 21}, {104, 7, 21}, {104, 8, 11}, {104, 9, 1}, {104, 12, 1}, 
    {105, 5, 11}, {105, 6, 1}, {105, 9, 21}, {105, 12, 21}, {106, 1, 11}, {106, 2, 1}, {106, 3, 1}, {106, 6, 21}, {106, 10, 11}, {106, 11, 1}, 
    {107, 2, 21}, {107, 3, 21}, {107, 4, 11}, {107, 7, 11}, {107, 8, 1}, {107, 11, 21}, {108, 5, 21}, {108, 6, 11}, {108, 10, 1}, {109, 1, 21}, 
    {109, 2, 11}, {109, 3, 11}, {109, 4, 1}, {109, 7, 1}, {109, 10, 21}, {109, 11, 11}, {110, 4, 21}, {110, 7, 21}, {110, 8, 11}, {110, 9, 1}, 
    {110, 12, 1}, {111, 5, 11}, {111, 6, 1}, {111, 9, 21}, {111, 12, 21}, {112, 1, 11}, {112, 2, 1}, {112, 3, 21}, {112, 4, 11}, {112, 7, 11}, 
    {112, 8, 1}, {112, 11, 21}, {113, 5, 1}, {113, 8, 21}, {113, 9, 11}, {113, 12, 11}, {114, 1, 1}, {114, 5, 21}, {114, 6, 11}, {114, 10, 1}, 
    {115, 1, 21}, {115, 2, 11}, {115, 3, 11}, {115, 4, 1}, {115, 7, 1}, {115, 10, 21}, {115, 11, 11}, {116, 5, 11}, {116, 6, 1}, {116, 9, 21}, 
    {116, 12, 21}, {117, 1, 11}, {117, 2, 1}, {117, 3, 1}, {117, 6, 21}, {117, 10, 11}, {117, 11, 1}, {118, 2, 21}, {118, 3, 21}, {118, 4, 11}, 
    {118, 7, 11}, {118, 8, 1}, {118, 11, 21}, {119, 5, 1}, {119, 8, 21}, {119, 9, 11}, {119, 12, 11}, {120, 1, 1}, {120, 3, 11}, {120, 4, 1}, 
    {120, 7, 1}, {120, 10, 21}, {120, 11, 11}, {121, 4, 21}, {121, 7, 21}, {121, 8, 11}, {121, 9, 1}, {121, 12, 1}, {122, 5, 11}, {122, 6, 1}, 
    {122, 9, 21}, {122, 12, 21}, {123, 1, 11}, {123, 2, 1}, {123, 3, 1}, {123, 6, 21}, {123, 10, 11}, {123, 11, 1}, {124, 2, 21}, {124, 5, 1}, 
    {124, 8, 21}, {124, 9, 11}, {124, 12, 11}, {125, 1, 1}, {125, 5, 21}, {125, 6, 11}, {125, 10, 1}, {126, 1, 21}, {126, 2, 11}, {126, 3, 11}, 
    {126, 4, 1}, {126, 7, 1}, {126, 10, 21}, {126, 11, 11}, {127, 4, 21}, {127, 7, 21}, {127, 8, 11}, {127, 9, 1}, {127, 12, 1}, {128, 3, 1}, 
    {128, 6, 21}, {128, 10, 11}, {128, 11, 1}, {129, 2, 21}, {129, 3, 21}, {129, 4, 11}, {129, 7, 11}, {129, 8, 1}, {129, 11, 21}, {130, 5, 1}, 
    {130, 8, 21}, {130, 9, 11}, {130, 12, 11}, {131, 1, 1}, {131, 5, 21}, {131, 6, 11}, {131, 10, 1}, {132, 1, 21}, {132, 2, 11}, {132, 4, 21}, 
    {132, 7, 21}, {132, 8, 11}, {132, 9, 1}, {132, 12, 1}, {133, 5, 11}, {133, 6, 1}, {133, 9, 21}, {133, 12, 21}, {134, 1, 11}, {134, 2, 1}, 
    {134, 3, 1}, {134, 6, 21}, {134, 10, 11}, {134, 11, 1}, {135, 2, 21}, {135, 3, 21}, {135, 4, 11}, {135, 7, 11}, {135, 8, 1}, {135, 11, 21}, 
    {136, 5, 21}, {136, 6, 11}, {136, 10, 1}, {137, 1, 21}, {137, 2, 11}, {137, 3, 11}, {137, 4, 1}, {137, 7, 1}, {137, 10, 21}, {137, 11, 11}, 
    {138, 4, 21}, {138, 7, 21}, {138, 8, 11}, {138, 9, 1}, {138, 12, 1}, {139, 5, 11}, {139, 6, 1}, {139, 9, 21}, {139, 12, 21}, {140, 1, 11}, 
    {140, 2, 1}, {140, 3, 21}, {140, 4, 11}, {140, 7, 11}, {140, 8, 1}, {140, 11, 21}, {141, 5, 1}, {141, 8, 21}, {141, 9, 11}, {141, 12, 11}, 
    {142, 1, 1}, {142, 5, 21}, {142, 6, 11}, {142, 10, 1}, {143, 1, 21}, {143, 2, 11}, {143, 3, 11}, {143, 4, 1}, {143, 7, 1}, {143, 10, 21}, 
    {143, 11, 11}, {144, 5, 11}, {144, 6, 1}, {144, 9, 21}, {144, 12, 21}, {145, 1, 11}, {145, 2, 1}, {145, 3, 1}, {145, 6, 21}, {145, 10, 11}, 
    {145, 11, 1}, {146, 2, 21}, {146, 3, 21}, {146, 4, 11}, {146, 7, 11}, {146, 8, 1}, {146, 11, 21}, {147, 5, 1}, {147, 8, 21}, {147, 9, 11}, 
    {147, 12, 11}, {148, 1, 1}, {148, 3, 11}, {148, 4, 1}, {148, 7, 1}, {148, 10, 21}, {148, 11, 11}, {149, 4, 21}, {149, 7, 21}, {149, 8, 11}, 
    {149, 9, 1}, {149, 12, 1}, {150, 5, 11}, {150, 6, 1}, {150, 9, 21}, {150, 12, 21}, {151, 1, 11}, {151, 2, 1}, {151, 3, 1}, {151, 6, 21}, 
    {151, 10, 11}, {151, 11, 1}, {152, 2, 21}, {152, 5, 1}, {152, 8, 21}, {152, 9, 11}, {152, 12, 11}, {153, 1, 1}, {153, 5, 21}, {153, 6, 11}, 
    {153, 10, 1}, {154, 1, 21}, {154, 2, 11}, {154, 3, 11}, {154, 4, 1}, {154, 7, 1}, {154, 10, 21}, {154, 11, 11}, {155, 4, 21}, {155, 7, 21}, 
    {155, 8, 11}, {155, 9, 1}, {155, 12, 1}, {156, 3, 1}, {156, 6, 21}, {156, 10, 11}, {156, 11, 1}, {157, 2, 21}, {157, 3, 21}, {157, 4, 11}, 
    {157, 7, 11}, {157, 8, 1}, {157, 11, 21}, {158, 5, 1}, {158, 8, 21}, {158, 9, 11}, {158, 12, 11}, {159, 1, 1}, {159, 5, 21}, {159, 6, 11}, 
    {159, 10, 1}, {160, 1, 21}, {160, 2, 11}, {160, 4, 21}, {160, 7, 21}, {160, 8, 11}, {160, 9, 1}, {160, 12, 1}, {161, 5, 11}, {161, 6, 1}, 
    {161, 9, 21}, {161, 12, 21}, {162, 1, 11}, {162, 2, 1}, {162, 3, 1}, {162, 6, 21}, {162, 10, 11}, {162, 11, 1}, {163, 2, 21}, {163, 3, 21}, 
    {163, 4, 11}, {163, 7, 11}, {163, 8, 1}, {163, 11, 21}, {164, 5, 21}, {164, 6, 11}, {164, 10, 1}, {165, 1, 21}, {165, 2, 11}, {165, 3, 11}, 
    {165, 4, 1}, {165, 7, 1}, {165, 10, 21}, {165, 11, 11}, {166, 4, 21}, {166, 7, 21}, {166, 8, 11}, {166, 9, 1}, {166, 12, 1}, {167, 5, 11}, 
    {167, 6, 1}, {167, 9, 21}, {167, 12, 21}, {168, 1, 11}, {168, 2, 1}, {168, 3, 21}, {168, 4, 11}, {168, 7, 11}, {168, 8, 1}, {168, 11, 21}, 
    {169, 5, 1}, {169, 8, 21}, {169, 9, 11}, {169, 12, 11}, {170, 1, 1}, {170, 5, 21}, {170, 6, 11}, {170, 10, 1}, {171, 1, 21}, {171, 2, 11}, 
    {171, 3, 11}, {171, 4, 1}, {171, 7, 1}, {171, 10, 21}, {171, 11, 11}, {172, 5, 11}, {172, 6, 1}, {172, 9, 21}, {172, 12, 21}, {173, 1, 11}, 
    {173, 2, 1}, {173, 3, 1}, {173, 6, 21}, {173, 10, 11}, {173, 11, 1}, {174, 2, 21}, {174, 3, 21}, {174, 4, 11}, {174, 7, 11}, {174, 8, 1}, 
    {174, 11, 21}, {175, 5, 1}, {175, 8, 21}, {175, 9, 11}, {175, 12, 11}, {176, 1, 1}, {176, 3, 11}, {176, 4, 1}, {176, 7, 1}, {176, 10, 21}, 
    {176, 11, 11}, {177, 4, 21}, {177, 7, 21}, {177, 8, 11}, {177, 9, 1}, {177, 12, 1}, {178, 5, 11}, {178, 6, 1}, {178, 9, 21}, {178, 12, 21}, 
    {179, 1, 11}, {179, 2, 1}, {179, 3, 1}, {179, 6, 21}, {179, 10, 11}, {179, 11, 1}, {180, 2, 21}, {180, 5, 1}, {180, 8, 21}, {180, 9, 11}, 
    {180, 12, 11}, {181, 1, 1}, {181, 5, 21}, {181, 6, 11}, {181, 10, 1}, {182, 1, 21}, {182, 2, 11}, {182, 3, 11}, {182, 4, 1}, {182, 7, 1}, 
    {182, 10, 21}, {182, 11, 11}, {183, 4, 21}, {183, 7, 21}, {183, 8, 11}, {183, 9, 1}, {183, 12, 1}, {184, 3, 1}, {184, 6, 21}, {184, 10, 11}, 
    {184, 11, 1}, {185, 2, 21}, {185, 3, 21}, {185, 4, 11}, {185, 7, 11}, {185, 8, 1}, {185, 11, 21}, {186, 5, 1}, {186, 8, 21}, {186, 9, 11}, 
    {186, 12, 11}, {187, 1, 1}, {187, 5, 21}, {187, 6, 11}, {187, 10, 1}, {188, 1, 21}, {188, 2, 11}, {188, 4, 21}, {188, 7, 21}, {188, 8, 11}, 
    {188, 9, 1}, {188, 12, 1}, {189, 5, 11}, {189, 6, 1}, {189, 9, 21}, {189, 12, 21}, {190, 1, 11}, {190, 2, 1}, {190, 3, 1}, {190, 6, 21}, 
    {190, 10, 11}, {190, 11, 1}, {191, 2, 21}, {191, 3, 21}, {191, 4, 11}, {191, 7, 11}, {191, 8, 1}, {191, 11, 21}, {192, 5, 21}, {192, 6, 11}, 
    {192, 10, 1}, {193, 1, 21}, {193, 2, 11}, {193, 3, 11}, {193, 4, 1}, {193, 7, 1}, {193, 10, 21}, {193, 11, 11}, {194, 4, 21}, {194, 7, 21}, 
    {194, 8, 11}, {194, 9, 1}, {194, 12, 1}, {195, 5, 11}, {195, 6, 1}, {195, 9, 21}, {195, 12, 21}, {196, 1, 11}, {196, 2, 1}, {196, 3, 21}, 
    {196, 4, 11}, {196, 7, 11}, {196, 8, 1}, {196, 11, 21}, {197, 5, 1}, {197, 8, 21}, {197, 9, 11}, {197, 12, 11}, {198, 1, 1}, {198, 5, 21}, 
    {198, 6, 11}, {198, 10, 1}, {199, 1, 21}, {199, 2, 11}, {199, 3, 11}, {199, 4, 1}, {199, 7, 1}, {199, 10, 21}, {199, 11, 11}, {200, 4, 21}, 
    {200, 7, 21}, {200, 8, 11}, {200, 9, 1}, {200, 12, 1}, {201, 5, 11}, {201, 6, 1}, {201, 9, 21}, {201, 12, 21}, {202, 1, 11}, {202, 2, 1}, 
    {202, 3, 1}, {202, 6, 21}, {202, 10, 11}, {202, 11, 1}, {203, 2, 21}, {203, 3, 21}, {203, 4, 11}, {203, 7, 11}, {203, 8, 1}, {203, 11, 21}, 
    {204, 5, 21}, {204, 6, 11}, {204, 10, 1}, {205, 1, 21}, {205, 2, 11}, {205, 3, 11}, {205, 4, 1}, {205, 7, 1}, {205, 10, 21}, {205, 11, 11}, 
    {206, 4, 21}, {206, 7, 21}, {206, 8, 11}, {206, 9, 1}, {206, 12, 1}, {207, 5, 11}, {207, 6, 1}, {207, 9, 21}, {207, 12, 21}, {208, 1, 11}, 
    {208, 2, 1}, {208, 3, 21}, {208, 4, 11}, {208, 7, 11}, {208, 8, 1}, {208, 11, 21}, {209, 5, 1}, {209, 8, 21}, {209, 9, 11}, {209, 12, 11}, 
    {210, 1, 1}, {210, 5, 21}, {210, 6, 11}, {210, 10, 1}, {211, 1, 21}, {211, 2, 11}, {211, 3, 11}, {211, 4, 1}, {211, 7, 1}, {211, 10, 21}, 
    {211, 11, 11}, {212, 5, 11}, {212, 6, 1}, {212, 9, 21}, {212, 12, 21}, {213, 1, 11}, {213, 2, 1}, {213, 3, 1}, {213, 6, 21}, {213, 10, 11}, 
    {213, 11, 1}, {214, 2, 21}, {214, 3, 21}, {214, 4, 11}, {214, 7, 11}, {214, 8, 1}, {214, 11, 21}, {215, 5, 1}, {215, 8, 21}, {215, 9, 11}, 
    {215, 12, 11}, {216, 1, 1}, {216, 3, 11}, {216, 4, 1}, {216, 7, 1}, {216, 10, 21}, {216, 11, 11}, {217, 4, 21}, {217, 7, 21}, {217, 8, 11}, 
    {217, 9, 1}, {217, 12, 1}, {218, 5, 11}, {218, 6, 1}, {218, 9, 21}, {218, 12, 21}, {219, 1, 11}, {219, 2, 1}, {219, 3, 1}, {219, 6, 21}, 
    {219, 10, 11}, {219, 11, 1}, {220, 2, 21}, {220, 5, 1}, {220, 8, 21}, {220, 9, 11}, {220, 12, 11}, {221, 1, 1}, {221, 5, 21}, {221, 6, 11}, 
    {221, 10, 1}, {222, 1, 21}, {222, 2, 11}, {222, 3, 11}, {222, 4, 1}, {222, 7, 1}, {222, 10, 21}, {222, 11, 11}, {223, 4, 21}, {223, 7, 21}, 
    {223, 8, 11}, {223, 9, 1}, {223, 12, 1}, {224, 3, 1}, {224, 6, 21}, {224, 10, 11}, {224, 11, 1}, {225, 2, 21}, {225, 3, 21}, {225, 4, 11}, 
    {225, 7, 11}, {225, 8, 1}, {225, 11, 21}, {226, 5, 1}, {226, 8, 21}, {226, 9, 11}, {226, 12, 11}, {227, 1, 1}, {227, 5, 21}, {227, 6, 11}, 
    {227, 10, 1}, {228, 1, 21}, {228, 2, 11}, {228, 4, 21}, {228, 7, 21}, {228, 8, 11}, {228, 9, 1}, {228, 12, 1}, {229, 5, 11}, {229, 6, 1}, 
    {229, 9, 21}, {229, 12, 21}, {230, 1, 11}, {230, 2, 1}, {230, 3, 1}, {230, 6, 21}, {230, 10, 11}, {230, 11, 1}, {231, 2, 21}, {231, 3, 21}, 
    {231, 4, 11}, {231, 7, 11}, {231, 8, 1}, {231, 11, 21}, {232, 5, 21}, {232, 6, 11}, {232, 10, 1}, {233, 1, 21}, {233, 2, 11}, {233, 3, 11}, 
    {233, 4, 1}, {233, 7, 1}, {233, 10, 21}, {233, 11, 11}, {234, 4, 21}, {234, 7, 21}, {234, 8, 11}, {234, 9, 1}, {234, 12, 1}, {235, 5, 11}, 
    {235, 6, 1}, {235, 9, 21}, {235, 12, 21}, {236, 1, 11}, {236, 2, 1}, {236, 3, 21}, {236, 4, 11}, {236, 7, 11}, {236, 8, 1}, {236, 11, 21}, 
    {237, 5, 1}, {237, 8, 21}, {237, 9, 11}, {237, 12, 11}, {238, 1, 1}, {238, 5, 21}, {238, 6, 11}, {238, 10, 1}, {239, 1, 21}, {239, 2, 11}, 
    {239, 3, 11}, {239, 4, 1}, {239, 7, 1}, {239, 10, 21}, {239, 11, 11}, {240, 5, 11}, {240, 6, 1}, {240, 9, 21}, {240, 12, 21}, {241, 1, 11}, 
    {241, 2, 1}, {241, 3, 1}, {241, 6, 21}, {241, 10, 11}, {241, 11, 1}, {242, 2, 21}, {242, 3, 21}, {242, 4, 11}, {242, 7, 11}, {242, 8, 1}, 
    {242, 11, 21}, {243, 5, 1}, {243, 8, 21}, {243, 9, 11}, {243, 12, 11}, {244, 1, 1}, {244, 3, 11}, {244, 4, 1}, {244, 7, 1}, {244, 10, 21}, 
    {244, 11, 11}, {245, 4, 21}, {245, 7, 21}, {245, 8, 11}, {245, 9, 1}, {245, 12, 1}, {246, 5, 11}, {246, 6, 1}, {246, 9, 21}, {246, 12, 21}, 
    {247, 1, 11}, {247, 2, 1}, {247, 3, 1}, {247, 6, 21}, {247, 10, 11}, {247, 11, 1}, {248, 2, 21}, {248, 5, 1}, {248, 8, 21}, {248, 9, 11}, 
    {248, 12, 11}, {249, 1, 1}, {249, 5, 21}, {249, 6, 11}, {249, 10, 1}, {250, 1, 21}, {250, 2, 11}, {250, 3, 11}, {250, 4, 1}, {250, 7, 1}, 
    {250, 10, 21}, {250, 11, 11}, {251, 4, 21}, {251, 7, 21}, {251, 8, 11}, {251, 9, 1}, {251, 12, 1}, {252, 3, 1}, {252, 6, 21}, {252, 10, 11}, 
    {252, 11, 1}, {253, 2, 21}, {253, 3, 21}, {253, 4, 11}, {253, 7, 11}, {253, 8, 1}, {253, 11, 21}, {254, 5, 1}, {254, 8, 21}, {254, 9, 11}, 
    {254, 12, 11}, {255, 1, 1}, {255, 5, 21}, {255, 6, 11}, {255, 10, 1}, {256, 1, 21}, {256, 2, 11}, {256, 4, 21}, {256, 7, 21}, {256, 8, 11}, 
    {256, 9, 1}, {256, 12, 1}, {257, 5, 11}, {257, 6, 1}, {257, 9, 21}, {257, 12, 21}, {258, 1, 11}, {258, 2, 1}, {258, 3, 1}, {258, 6, 21}, 
    {258, 10, 11}, {258, 11, 1}, {259, 2, 21}, {259, 3, 21}, {259, 4, 11}, {259, 7, 11}, {259, 8, 1}, {259, 11, 21}, {260, 5, 21}, {260, 6, 11}, 
    {260, 10, 1}, {261, 1, 21}, {261, 2, 11}, {261, 3, 11}, {261, 4, 1}, {261, 7, 1}, {261, 10, 21}, {261, 11, 11}, {262, 4, 21}, {262, 7, 21}, 
    {262, 8, 11}, {262, 9, 1}, {262, 12, 1}, {263, 5, 11}, {263, 6, 1}, {263, 9, 21}, {263, 12, 21}, {264, 1, 11}, {264, 2, 1}, {264, 3, 21}, 
    {264, 4, 11}, {264, 7, 11}, {264, 8, 1}, {264, 11, 21}, {265, 5, 1}, {265, 8, 21}, {265, 9, 11}, {265, 12, 11}, {266, 1, 1}, {266, 5, 21}, 
    {266, 6, 11}, {266, 10, 1}, {267, 1, 21}, {267, 2, 11}, {267, 3, 11}, {267, 4, 1}, {267, 7, 1}, {267, 10, 21}, {267, 11, 11}, {268, 5, 11}, 
    {268, 6, 1}, {268, 9, 21}, {268, 12, 21}, {269, 1, 11}, {269, 2, 1}, {269, 3, 1}, {269, 6, 21}, {269, 10, 11}, {269, 11, 1}, {270, 2, 21}, 
    {270, 3, 21}, {270, 4, 11}, {270, 7, 11}, {270, 8, 1}, {270, 11, 21}, {271, 5, 1}, {271, 8, 21}, {271, 9, 11}, {271, 12, 11}, {272, 1, 1}, 
    {272, 3, 11}, {272, 4, 1}, {272, 7, 1}, {272, 10, 21}, {272, 11, 11}, {273, 4, 21}, {273, 7, 21}, {273, 8, 11}, {273, 9, 1}, {273, 12, 1}, 
    {274, 5, 11}, {274, 6, 1}, {274, 9, 21}, {274, 12, 21}, {275, 1, 11}, {275, 2, 1}, {275, 3, 1}, {275, 6, 21}, {275, 10, 11}, {275, 11, 1}, 
    {276, 2, 21}, {276, 5, 1}, {276, 8, 21}, {276, 9, 11}, {276, 12, 11}, {277, 1, 1}, {277, 5, 21}, {277, 6, 11}, {277, 10, 1}, {278, 1, 21}, 
    {278, 2, 11}, {278, 3, 11}, {278, 4, 1}, {278, 7, 1}, {278, 10, 21}, {278, 11, 11}, {279, 4, 21}, {279, 7, 21}, {279, 8, 11}, {279, 9, 1}, 
    {279, 12, 1}, {280, 3, 1}, {280, 6, 21}, {280, 10, 11}, {280, 11, 1}, {281, 2, 21}, {281, 3, 21}, {281, 4, 11}, {281, 7, 11}, {281, 8, 1}, 
    {281, 11, 21}, {282, 5, 1}, {282, 8, 21}, {282, 9, 11}, {282, 12, 11}, {283, 1, 1}, {283, 5, 21}, {283, 6, 11}, {283, 10, 1}, {284, 1, 21}, 
    {284, 2, 11}, {284, 4, 21}, {284, 7, 21}, {284, 8, 11}, {284, 9, 1}, {284, 12, 1}, {285, 5, 11}, {285, 6, 1}, {285, 9, 21}, {285, 12, 21}, 
    {286, 1, 11}, {286, 2, 1}, {286, 3, 1}, {286, 6, 21}, {286, 10, 11}, {286, 11, 1}, {287, 2, 21}, {287, 3, 21}, {287, 4, 11}, {287, 7, 11}, 
    {287, 8, 1}, {287, 11, 21}, {288, 5, 21}, {288, 6, 11}, {288, 10, 1}, {289, 1, 21}, {289, 2, 11}, {289, 3, 11}, {289, 4, 1}, {289, 7, 1}, 
    {289, 10, 21}, {289, 11, 11}, {290, 4, 21}, {290, 7, 21}, {290, 8, 11}, {290, 9, 1}, {290, 12, 1}, {291, 5, 11}, {291, 6, 1}, {291, 9, 21}, 
    {291, 12, 21}, {292, 1, 11}, {292, 2, 1}, {292, 3, 21}, {292, 4, 11}, {292, 7, 11}, {292, 8, 1}, {292, 11, 21}, {293, 5, 1}, {293, 8, 21}, 
    {293, 9, 11}, {293, 12, 11}, {294, 1, 1}, {294, 5, 21}, {294, 6, 11}, {294, 10, 1}, {295, 1, 21}, {295, 2, 11}, {295, 3, 11}, {295, 4, 1}, 
    {295, 7, 1}, {295, 10, 21}, {295, 11, 11}, {296, 5, 11}, {296, 6, 1}, {296, 9, 21}, {296, 12, 21}, {297, 1, 11}, {297, 2, 1}, {297, 3, 1}, 
    {297, 6, 21}, {297, 10, 11}, {297, 11, 1}, {298, 2, 21}, {298, 3, 21}, {298, 4, 11}, {298, 7, 11}, {298, 8, 1}, {298, 11, 21}, {299, 5, 1}, 
    {299, 8, 21}, {299, 9, 11}, {299, 12, 11}, {300, 1, 1}, {300, 5, 21}, {300, 6, 11}, {300, 10, 1}, {301, 1, 21}, {301, 2, 11}, {301, 3, 11}, 
    {301, 4, 1}, {301, 7, 1}, {301, 10, 21}, {301, 11, 11}, {302, 4, 21}, {302, 7, 21}, {302, 8, 11}, {302, 9, 1}, {302, 12, 1}, {303, 5, 11}, 
    {303, 6, 1}, {303, 9, 21}, {303, 12, 21}, {304, 1, 11}, {304, 2, 1}, {304, 3, 21}, {304, 4, 11}, {304, 7, 11}, {304, 8, 1}, {304, 11, 21}, 
    {305, 5, 1}, {305, 8, 21}, {305, 9, 11}, {305, 12, 11}, {306, 1, 1}, {306, 5, 21}, {306, 6, 11}, {306, 10, 1}, {307, 1, 21}, {307, 2, 11}, 
    {307, 3, 11}, {307, 4, 1}, {307, 7, 1}, {307, 10, 21}, {307, 11, 11}, {308, 5, 11}, {308, 6, 1}, {308, 9, 21}, {308, 12, 21}, {309, 1, 11}, 
    {309, 2, 1}, {309, 3, 1}, {309, 6, 21}, {309, 10, 11}, {309, 11, 1}, {310, 2, 21}, {310, 3, 21}, {310, 4, 11}, {310, 7, 11}, {310, 8, 1}, 
    {310, 11, 21}, {311, 5, 1}, {311, 8, 21}, {311, 9, 11}, {311, 12, 11}, {312, 1, 1}, {312, 3, 11}, {312, 4, 1}, {312, 7, 1}, {312, 10, 21}, 
    {312, 11, 11}, {313, 4, 21}, {313, 7, 21}, {313, 8, 11}, {313, 9, 1}, {313, 12, 1}, {314, 5, 11}, {314, 6, 1}, {314, 9, 21}, {314, 12, 21}, 
    {315, 1, 11}, {315, 2, 1}, {315, 3, 1}, {315, 6, 21}, {315, 10, 11}, {315, 11, 1}, {316, 2, 21}, {316, 5, 1}, {316, 8, 21}, {316, 9, 11}, 
    {316, 12, 11}, {317, 1, 1}, {317, 5, 21}, {317, 6, 11}, {317, 10, 1}, {318, 1, 21}, {318, 2, 11}, {318, 3, 11}, {318, 4, 1}, {318, 7, 1}, 
    {318, 10, 21}, {318, 11, 11}, {319, 4, 21}, {319, 7, 21}, {319, 8, 11}, {319, 9, 1}, {319, 12, 1}, {320, 3, 1}, {320, 6, 21}, {320, 10, 11}, 
    {320, 11, 1}, {321, 2, 21}, {321, 3, 21}, {321, 4, 11}, {321, 7, 11}, {321, 8, 1}, {321, 11, 21}, {322, 5, 1}, {322, 8, 21}, {322, 9, 11}, 
    {322, 12, 11}, {323, 1, 1}, {323, 5, 21}, {323, 6, 11}, {323, 10, 1}, {324, 1, 21}, {324, 2, 11}, {324, 4, 21}, {324, 7, 21}, {324, 8, 11}, 
    {324, 9, 1}, {324, 12, 1}, {325, 5, 11}, {325, 6, 1}, {325, 9, 21}, {325, 12, 21}, {326, 1, 11}, {326, 2, 1}, {326, 3, 1}, {326, 6, 21}, 
    {326, 10, 11}, {326, 11, 1}, {327, 2, 21}, {327, 3, 21}, {327, 4, 11}, {327, 7, 11}, {327, 8, 1}, {327, 11, 21}, {328, 5, 21}, {328, 6, 11}, 
    {328, 10, 1}, {329, 1, 21}, {329, 2, 11}, {329, 3, 11}, {329, 4, 1}, {329, 7, 1}, {329, 10, 21}, {329, 11, 11}, {330, 4, 21}, {330, 7, 21}, 
    {330, 8, 11}, {330, 9, 1}, {330, 12, 1}, {331, 5, 11}, {331, 6, 1}, {331, 9, 21}, {331, 12, 21}, {332, 1, 11}, {332, 2, 1}, {332, 3, 21}, 
    {332, 4, 11}, {332, 7, 11}, {332, 8, 1}, {332, 11, 21}, {333, 5, 1}, {333, 8, 21}, {333, 9, 11}, {333, 12, 11}, {334, 1, 1}, {334, 5, 21}, 
    {334, 6, 11}, {334, 10, 1}, {335, 1, 21}, {335, 2, 11}, {335, 3, 11}, {335, 4, 1}, {335, 7, 1}, {335, 10, 21}, {335, 11, 11}, {336, 5, 11}, 
    {336, 6, 1}, {336, 9, 21}, {336, 12, 21}, {337, 1, 11}, {337, 2, 1}, {337, 3, 1}, {337, 6, 21}, {337, 10, 11}, {337, 11, 1}, {338, 2, 21}, 
    {338, 3, 21}, {338, 4, 11}, {338, 7, 11}, {338, 8, 1}, {338, 11, 21}, {339, 5, 1}, {339, 8, 21}, {339, 9, 11}, {339, 12, 11}, {340, 1, 1}, 
    {340, 3, 11}, {340, 4, 1}, {340, 7, 1}, {340, 10, 21}, {340, 11, 11}, {341, 4, 21}, {341, 7, 21}, {341, 8, 11}, {341, 9, 1}, {341, 12, 1}, 
    {342, 5, 11}, {342, 6, 1}, {342, 9, 21}, {342, 12, 21}, {343, 1, 11}, {343, 2, 1}, {343, 3, 1}, {343, 6, 21}, {343, 10, 11}, {343, 11, 1}, 
    {344, 2, 21}, {344, 5, 1}, {344, 8, 21}, {344, 9, 11}, {344, 12, 11}, {345, 1, 1}, {345, 5, 21}, {345, 6, 11}, {345, 10, 1}, {346, 1, 21}, 
    {346, 2, 11}, {346, 3, 11}, {346, 4, 1}, {346, 7, 1}, {346, 10, 21}, {346, 11, 11}, {347, 4, 21}, {347, 7, 21}, {347, 8, 11}, {347, 9, 1}, 
    {347, 12, 1}, {348, 3, 1}, {348, 6, 21}, {348, 10, 11}, {348, 11, 1}, {349, 2, 21}, {349, 3, 21}, {349, 4, 11}, {349, 7, 11}, {349, 8, 1}, 
    {349, 11, 21}, {350, 5, 1}, {350, 8, 21}, {350, 9, 11}, {350, 12, 11}, {351, 1, 1}, {351, 5, 21}, {351, 6, 11}, {351, 10, 1}, {352, 1, 21}, 
    {352, 2, 11}, {352, 4, 21}, {352, 7, 21}, {352, 8, 11}, {352, 9, 1}, {352, 12, 1}, {353, 5, 11}, {353, 6, 1}, {353, 9, 21}, {353, 12, 21}, 
    {354, 1, 11}, {354, 2, 1}, {354, 3, 1}, {354, 6, 21}, {354, 10, 11}, {354, 11, 1}, {355, 2, 21}, {355, 3, 21}, {355, 4, 11}, {355, 7, 11}, 
    {355, 8, 1}, {355, 11, 21}, {356, 5, 21}, {356, 6, 11}, {356, 10, 1}, {357, 1, 21}, {357, 2, 11}, {357, 3, 11}, {357, 4, 1}, {357, 7, 1}, 
    {357, 10, 21}, {357, 11, 11}, {358, 4, 21}, {358, 7, 21}, {358, 8, 11}, {358, 9, 1}, {358, 12, 1}, {359, 5, 11}, {359, 6, 1}, {359, 9, 21}, 
    {359, 12, 21}, {360, 1, 11}, {360, 2, 1}, {360, 3, 21}, {360, 4, 11}, {360, 7, 11}, {360, 8, 1}, {360, 11, 21}, {361, 5, 1}, {361, 8, 21}, 
    {361, 9, 11}, {361, 12, 11}, {362, 1, 1}, {362, 5, 21}, {362, 6, 11}, {362, 10, 1}, {363, 1, 21}, {363, 2, 11}, {363, 3, 11}, {363, 4, 1}, 
    {363, 7, 1}, {363, 10, 21}, {363, 11, 11}, {364, 5, 11}, {364, 6, 1}, {364, 9, 21}, {364, 12, 21}, {365, 1, 11}, {365, 2, 1}, {365, 3, 1}, 
    {365, 6, 21}, {365, 10, 11}, {365, 11, 1}, {366, 2, 21}, {366, 3, 21}, {366, 4, 11}, {366, 7, 11}, {366, 8, 1}, {366, 11, 21}, {367, 5, 1}, 
    {367, 8, 21}, {367, 9, 11}, {367, 12, 11}, {368, 1, 1}, {368, 3, 11}, {368, 4, 1}, {368, 7, 1}, {368, 10, 21}, {368, 11, 11}, {369, 4, 21}, 
    {369, 7, 21}, {369, 8, 11}, {369, 9, 1}, {369, 12, 1}, {370, 5, 11}, {370, 6, 1}, {370, 9, 21}, {370, 12, 21}, {371, 1, 11}, {371, 2, 1}, 
    {371, 3, 1}, {371, 6, 21}, {371, 10, 11}, {371, 11, 1}, {372, 2, 21}, {372, 5, 1}, {372, 8, 21}, {372, 9, 11}, {372, 12, 11}, {373, 1, 1}, 
    {373, 5, 21}, {373, 6, 11}, {373, 10, 1}, {374, 1, 21}, {374, 2, 11}, {374, 3, 11}, {374, 4, 1}, {374, 7, 1}, {374, 10, 21}, {374, 11, 11}, 
    {375, 4, 21}, {375, 7, 21}, {375, 8, 11}, {375, 9, 1}, {375, 12, 1}, {376, 3, 1}, {376, 6, 21}, {376, 10, 11}, {376, 11, 1}, {377, 2, 21}, 
    {377, 3, 21}, {377, 4, 11}, {377, 7, 11}, {377, 8, 1}, {377, 11, 21}, {378, 5, 1}, {378, 8, 21}, {378, 9, 11}, {378, 12, 11}, {379, 1, 1}, 
    {379, 5, 21}, {379, 6, 11}, {379, 10, 1}, {380, 1, 21}, {380, 2, 11}, {380, 4, 21}, {380, 7, 21}, {380, 8, 11}, {380, 9, 1}, {380, 12, 1}, 
    {381, 5, 11}, {381, 6, 1}, {381, 9, 21}, {381, 12, 21}, {382, 1, 11}, {382, 2, 1}, {382, 3, 1}, {382, 6, 21}, {382, 10, 11}, {382, 11, 1}, 
    {383, 2, 21}, {383, 3, 21}, {383, 4, 11}, {383, 7, 11}, {383, 8, 1}, {383, 11, 21}, {384, 5, 21}, {384, 6, 11}, {384, 10, 1}, {385, 1, 21}, 
    {385, 2, 11}, {385, 3, 11}, {385, 4, 1}, {385, 7, 1}, {385, 10, 21}, {385, 11, 11}, {386, 4, 21}, {386, 7, 21}, {386, 8, 11}, {386, 9, 1}, 
    {386, 12, 1}, {387, 5, 11}, {387, 6, 1}, {387, 9, 21}, {387, 12, 21}, {388, 1, 11}, {388, 2, 1}, {388, 3, 21}, {388, 4, 11}, {388, 7, 11}, 
    {388, 8, 1}, {388, 11, 21}, {389, 5, 1}, {389, 8, 21}, {389, 9, 11}, {389, 12, 11}, {390, 1, 1}, {390, 5, 21}, {390, 6, 11}, {390, 10, 1}, 
    {391, 1, 21}, {391, 2, 11}, {391, 3, 11}, {391, 4, 1}, {391, 7, 1}, {391, 10, 21}, {391, 11, 11}, {392, 5, 11}, {392, 6, 1}, {392, 9, 21}, 
    {392, 12, 21}, {393, 1, 11}, {393, 2, 1}, {393, 3, 1}, {393, 6, 21}, {393, 10, 11}, {393, 11, 1}, {394, 2, 21}, {394, 3, 21}, {394, 4, 11}, 
    {394, 7, 11}, {394, 8, 1}, {394, 11, 21}, {395, 5, 1}, {395, 8, 21}, {395, 9, 11}, {395, 12, 11}, {396, 1, 1}, {396, 3, 11}, {396, 4, 1}, 
    {396, 7, 1}, {396, 10, 21}, {396, 11, 11}, {397, 4, 21}, {397, 7, 21}, {397, 8, 11}, {397, 9, 1}, {397, 12, 1}, {398, 5, 11}, {398, 6, 1}, 
    {398, 9, 21}, {398, 12, 21}, {399, 1, 11}, {399, 2, 1}, {399, 3, 1}, {399, 6, 21}, {399, 10, 11}, {399, 11, 1}
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int y, m, d, n;
        cin >> y >> m >> d >> n;
        long long yy = y;
        y %= 400;
        long long i;
        for (i = 0; i < N; i++)
        {
            if (biao[i][0] == y && biao[i][1] == m && biao[i][2] == d)
            {
                break;
            }
        }
        i += n - 1;
        long long cnt = i / N;
        long long pos = i % N;
        printf("%lld %d %d\n", yy / 400 * 400 + cnt * 400 + biao[pos][0], biao[pos][1], biao[pos][2]);
    }
    return 0;
}