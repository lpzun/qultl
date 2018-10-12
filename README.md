# QuLTL
A model checker for QuLTL.

## 1. Introduction to QuLTL
QuLTL is a variant of LTL for data structure __queue__. 

### Syntax

```
phi ::= msg
     | qexpr
     | X phi
     | G phi
     | phi U phi
     
qexpr ::= literal
       | true
       | false
       | !qexpr
       | qexpr & qexpr
       | qexpr | qexpr
       | qexpr -> qexpr
     
literal ::= atom brop atom
         
brop := > | = | < | >= | <=

;; index ::= [i]: unsupporting for now
         
atom ::= #msg
      | c
      | []
      | atom + atom
      | atom - atom
      
c ::= constant
;; i ::= constant unsupported for now

```
### Semantics

## 2. QuLTL Model Checker

For now, we assume that Q is always bounded.
         
