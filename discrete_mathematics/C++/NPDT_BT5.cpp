#include <iostream>
using namespace std;

int main() {
   bool p, q, r;
   bool ans = 0;
//p and T = p
   for (int i = 0; i < 2; ++i) {
      p = i;
      if ((p && 1) == p)
         ans = 1;
   }

   cout << "p and true = p: " << ans << endl;

//p or F = p
   for (int i = 0; i < 2; ++i) {
      p = i;
      if ((p || 0) == p)
         ans = 1;
   }
   cout << "p or false = p: " << ans << endl << endl;

//p and T = T
   for (int i = 0; i < 2; ++i) {
      p = i;
      if ((p || 1) == 1)
         ans = 1;
   }
   cout << "p or true = true: " << ans << endl;

//p and F = F
   for (int i = 0; i < 2; ++i) {
      p = i;
      if ((p && 0) == 0)
         ans = 1;
   }

   cout << "p and false = false: " << ans << endl << endl;

//p or p = p
   for (int i = 0; i < 2; ++i) {
      p = i;
      if ((p || p) == p)
         ans = 1;
   }

   cout << "p or p = p: " << ans << endl;

//p and p = p
   for (int i = 0; i < 2; ++i) {
      p = i;
      if ((p && p) == p)
         ans = 1;
   }

   cout << "p and p = p: " << ans << endl << endl;

//!(!p) = p
   for (int i = 0; i < 2; ++i) {
      p = i;
      if (!(!p) == p)
         ans = 1;
   }

   cout << "!(!p) = p: " << ans << endl << endl;

//p or q = q or p
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      if ((p || q) == (q || p))
         ans = 1;
   }

   cout << "p or q = q or p: " << ans << endl;

//p and q = q and p
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      if ((p && q) == (q && p))
         ans = 1;
   }

   cout << "p and q = q and p: " << ans << endl << endl;



//(p or q) or r = p or (q or r)
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      for (int k = 0; k < 2; ++k)
         r = k;
      bool left = (p || q) || r;
      bool right = p || (q || r);
      if (left == right)
         ans = 1;
   }

   cout << "(p or q) or r = p or (q or r): " << ans << endl;

//(p and q) and r = p and (q and r)
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      for (int k = 0; k < 2; ++k)
         r = k;
      bool left = (p && q) && r;
      bool right = p && (q && r);
      if (left == right)
         ans = 1;
   }

   cout << "(p and q) and r = p and (q and r): " << ans << endl << endl;

//p or (q and r) = (p or q) and (p or r)
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      for (int k = 0; k < 2; ++k)
         r = k;
      bool left = p || (q && r);
      bool right = (p || q) && (p || r);
      if (left == right)
         ans = 1;
   }

   cout << "p or (q and r) = (p or q) and (p or r): " << ans << endl;

//p and (q or r) = (p and q) or (p and r)
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      for (int k = 0; k < 2; ++k)
         r = k;
      bool left = p || (q && r);
      bool right = (p || q) && (p || r);
      if (left == right)
         ans = 1;
   }

   cout << "p and (q or r) = (p and q) or (p and r): " << ans << endl << endl;

//!(p and q) = !p or !q
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      bool left = !(p && q);
      bool right = !p || !q;
      if (left == right)
         ans = 1;
   }

   cout << "!(p and q) = !p or !q: " << ans << endl;

//!(p or q) = !p and !q
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      bool left = !(p || q);
      bool right = !p && !q;
      if (left == right)
         ans = 1;
   }

   cout << "!(p or q) = !p and !q: " << ans << endl << endl;

//p or (p and q) = p
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      bool left = p || (p && q);
      bool right = p;
      if (left == right)
         ans = 1;
   }

   cout << "p or (p and q) = p: " << ans << endl;

//p and (p or q) = p
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      bool left = p && (p || q);
      bool right = p;
      if (left == right)
         ans = 1;
   }

   cout << "p and (p or q) = p: " << ans << endl << endl;

//p or !p = true
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      bool left = p || !p;
      bool right = 1;
      if (left == right)
         ans = 1;
   }

   cout << "p or !p = true: " << ans << endl;

//p and !p = false
   for (int i = 0; i < 2; ++i) {
      p = i;
      for (int j = 0; j < 2; ++j)
         q = j;
      bool left = p && !p;
      bool right = 0;
      if (left == right)
         ans = 1;
   }

   cout << "p and !p = false: " << ans << endl;

}