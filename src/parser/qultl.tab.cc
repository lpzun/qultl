// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 30 "qultl.y" // lalr1.cc:404


#line 39 "qultl.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "qultl.tab.hh"

// User implementation prologue.
#line 78 "qultl.y" // lalr1.cc:412

  extern int yylex(yy::qultl::semantic_type *yylval, yy::qultl::location_type* yylloc);

#line 56 "qultl.tab.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 142 "qultl.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  qultl::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  qultl::qultl (qultl_helper &qh_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      qh (qh_yyarg)
  {}

  qultl::~qultl ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  qultl::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  qultl::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  qultl::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  qultl::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  qultl::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  qultl::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  qultl::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  qultl::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  qultl::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  qultl::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  qultl::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  qultl::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  qultl::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  qultl::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  qultl::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  qultl::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  qultl::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  qultl::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  qultl::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  qultl::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  qultl::symbol_number_type
  qultl::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  qultl::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  qultl::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  qultl::stack_symbol_type&
  qultl::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  qultl::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  qultl::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  qultl::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  qultl::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  qultl::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  qultl::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  qultl::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  qultl::debug_level_type
  qultl::debug_level () const
  {
    return yydebug_;
  }

  void
  qultl::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline qultl::state_type
  qultl::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  qultl::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  qultl::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  qultl::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 82 "qultl.y" // lalr1.cc:745
{
  // add filename to location info here
  yyla.location.begin.filename = yyla.location.end.filename = new std::string("stdin");
 }

#line 521 "qultl.tab.cc" // lalr1.cc:745

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 92 "qultl.y" // lalr1.cc:859
    {}
#line 631 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 95 "qultl.y" // lalr1.cc:859
    {}
#line 637 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 96 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::TMP_U);
 }
#line 645 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 101 "qultl.y" // lalr1.cc:859
    {}
#line 651 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 102 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::TMP_F);
}
#line 659 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 105 "qultl.y" // lalr1.cc:859
    {
   qh.parse_phi(expr_op::TMP_G);
}
#line 667 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 108 "qultl.y" // lalr1.cc:859
    {
   qh.parse_phi(expr_op::TMP_X);
}
#line 675 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 113 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::PARENTHSIS);
 }
#line 683 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 116 "qultl.y" // lalr1.cc:859
    {
}
#line 690 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 118 "qultl.y" // lalr1.cc:859
    {
}
#line 697 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 122 "qultl.y" // lalr1.cc:859
    {}
#line 703 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 123 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::IMPLICATION);
 }
#line 711 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 128 "qultl.y" // lalr1.cc:859
    {}
#line 717 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 129 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::OR);
 }
#line 725 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 134 "qultl.y" // lalr1.cc:859
    {}
#line 731 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 135 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::AND);
 }
#line 739 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 140 "qultl.y" // lalr1.cc:859
    {}
#line 745 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 141 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::NEGATION);
 }
#line 753 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 146 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::PARENTHSIS);
 }
#line 761 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 149 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::CONST_T);
  }
#line 769 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 152 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::CONST_F);
  }
#line 777 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 155 "qultl.y" // lalr1.cc:859
    {}
#line 783 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 158 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::EQUAL);
}
#line 791 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 161 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::NOT_EQUAL);
}
#line 799 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 164 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::LESS_THAN);
}
#line 807 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 167 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::GREATER_THAN);
}
#line 815 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 170 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::LESS_THAN_EQ);
}
#line 823 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 173 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::GREATER_THAN_EQ);
}
#line 831 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 178 "qultl.y" // lalr1.cc:859
    {}
#line 837 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 179 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::MULTIPLICATION);
 }
#line 845 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 184 "qultl.y" // lalr1.cc:859
    {}
#line 851 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 185 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::ADDITION);
 }
#line 859 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 190 "qultl.y" // lalr1.cc:859
    {}
#line 865 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 191 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::SUBTRACTION);
 }
#line 873 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 196 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::PARENTHSIS);
}
#line 881 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 199 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::COUNT);
}
#line 889 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 202 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(expr_op::SIZE);
}
#line 897 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 205 "qultl.y" // lalr1.cc:859
    { }
#line 903 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 208 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi((yystack_[0].value.t_str));
  free((yystack_[0].value.t_str));
}
#line 912 "qultl.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 214 "qultl.y" // lalr1.cc:859
    {
  qh.parse_phi(std::to_string((yystack_[0].value.t_val)));
 }
#line 920 "qultl.tab.cc" // lalr1.cc:859
    break;


#line 924 "qultl.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  qultl::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  qultl::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char qultl::yypact_ninf_ = -21;

  const signed char qultl::yytable_ninf_ = -1;

  const signed char
  qultl::yypact_[] =
  {
       3,     3,     3,     3,    58,   -15,   -21,   -21,   -21,   -21,
       3,   -20,    12,    -5,   -21,   -21,     4,     7,     9,   -21,
     -21,   -21,    57,     8,    18,   -21,   -21,   -21,   -21,   -21,
     -21,    40,   -21,   -21,   -13,   -11,    38,   -21,   -21,     3,
     -21,    40,    40,    40,    61,    61,    61,    61,    61,    61,
      61,    61,    61,   -11,   -21,   -21,   -21,   -21,     7,     9,
     -21,    61,     8,    20,    20,    20,    20,    20,    20,    18,
     -21,     5
  };

  const unsigned char
  qultl::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,    21,    22,    41,    40,
       0,     0,     0,     0,     3,     5,    11,    12,    14,    16,
      18,    23,     0,    30,    32,    34,    10,    39,     6,     7,
       8,     0,    19,    37,     0,    11,     0,    38,     1,     0,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    20,    36,     4,    13,    15,
      17,     0,    31,    24,    25,    26,    27,    28,    29,    33,
      35,     0
  };

  const signed char
  qultl::yypgoto_[] =
  {
     -21,    22,   -21,     2,   -21,    -1,     1,     6,     0,    41,
     -21,   -10,    14,    -7,    -6,    44,   -21
  };

  const signed char
  qultl::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27
  };

  const unsigned char
  qultl::yytable_[] =
  {
      36,    39,    41,    28,    29,    30,     1,     2,     3,    35,
       9,    37,    38,     4,    44,    51,    54,    41,    55,    42,
      43,    36,    40,     5,     6,     7,    52,     8,     9,    44,
      53,    10,    34,    11,    56,    63,    64,    65,    66,    67,
      68,    57,    58,    60,    69,    32,    70,    44,    59,    33,
       4,    71,    45,    46,    47,    48,    49,    50,    62,     0,
       5,     6,     7,     0,     8,     0,    44,    56,    31,     0,
      11,    45,    46,    47,    48,    49,    50,     0,     5,     6,
       7,     5,     8,     0,     0,     8,    31,     0,    11,    61,
       0,    11
  };

  const signed char
  qultl::yycheck_[] =
  {
      10,     6,    13,     1,     2,     3,     3,     4,     5,    10,
      25,    31,     0,    10,     9,     7,    29,    13,    29,    12,
      11,    31,    27,    20,    21,    22,     8,    24,    25,     9,
      31,    28,    10,    30,    29,    45,    46,    47,    48,    49,
      50,    39,    41,    43,    51,     4,    52,     9,    42,     5,
      10,    61,    14,    15,    16,    17,    18,    19,    44,    -1,
      20,    21,    22,    -1,    24,    -1,     9,    29,    28,    -1,
      30,    14,    15,    16,    17,    18,    19,    -1,    20,    21,
      22,    20,    24,    -1,    -1,    24,    28,    -1,    30,    28,
      -1,    30
  };

  const unsigned char
  qultl::yystos_[] =
  {
       0,     3,     4,     5,    10,    20,    21,    22,    24,    25,
      28,    30,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    35,    35,
      35,    28,    41,    47,    33,    37,    43,    31,     0,     6,
      27,    13,    12,    11,     9,    14,    15,    16,    17,    18,
      19,     7,     8,    37,    29,    29,    29,    35,    38,    39,
      40,    28,    44,    43,    43,    43,    43,    43,    43,    45,
      46,    43
  };

  const unsigned char
  qultl::yyr1_[] =
  {
       0,    32,    33,    34,    34,    35,    35,    35,    35,    36,
      36,    36,    37,    37,    38,    38,    39,    39,    40,    40,
      41,    41,    41,    41,    42,    42,    42,    42,    42,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      47,    48
  };

  const unsigned char
  qultl::yyr2_[] =
  {
       0,     2,     2,     1,     3,     1,     2,     2,     2,     3,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     2,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     3,     2,     2,     1,
       1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const qultl::yytname_[] =
  {
  "$end", "error", "$undefined", "\"F\"", "\"G\"", "\"X\"", "\"U\"",
  "\"+\"", "\"-\"", "\"*\"", "\"!\"", "\"&\"", "\"|\"", "\"->\"", "\"=\"",
  "\"!=\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"", "\"#\"", "\"true\"",
  "\"false\"", "T_END", "T_NAT", "T_IDEN", "T_DELIM", "';'", "'('", "')'",
  "'['", "']'", "$accept", "phi", "bin_phi", "una_phi", "prm_phi", "expr",
  "or_expr", "and_expr", "una_expr", "prm_expr", "literal", "qula_expr",
  "qula_add_expr", "qula_sub_expr", "qula_prm_expr", "msg", "constant", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  qultl::yyrline_[] =
  {
       0,    92,    92,    95,    96,   101,   102,   105,   108,   113,
     116,   118,   122,   123,   128,   129,   134,   135,   140,   141,
     146,   149,   152,   155,   158,   161,   164,   167,   170,   173,
     178,   179,   184,   185,   190,   191,   196,   199,   202,   205,
     208,   214
  };

  // Print the state stack on the debug stream.
  void
  qultl::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  qultl::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  qultl::token_number_type
  qultl::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
    };
    const unsigned int user_token_number_max_ = 281;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1394 "qultl.tab.cc" // lalr1.cc:1167
#line 219 "qultl.y" // lalr1.cc:1168


/*******************************************************************************
 * ** From here, 
 *         functions used in parser, defined in c++
 *
 *    Mar. 2013
 ******************************************************************************/
namespace yy {
  void qultl::error(location const &loc, const std::string& s) {
    std::cerr << "error at " << loc << ": " << s << std::endl;
  }
}