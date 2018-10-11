# QuLTL
A model checker for QuLTL.

QuLTL is a variant of LTL for data structure __queue__. 

```
phi ::= msg
     | true
     | false
     | qexpr
     | X phi
     | G phi
     | phi U phi
     
qexpr ::= literal
       | ~qexpr
       | qexpr & qexpr
       | qexpr | qexpr
       | qexpr -> qexpr
       | qexpr <-> qexpr
     
literal ::= qula brop qula
         | qula brop c
         | c brop qula
         
brop := > | = | < | >= | <=
         
qula ::= Q[i] 
      | #msg
      | c
      | size
      | qula + qula
      | qula - qula
      
c ::= constant
```

         
