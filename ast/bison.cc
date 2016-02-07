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

#line 37 "bison.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "bison.hh"

// User implementation prologue.

#line 51 "bison.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 39 "bison.yy" // lalr1.cc:413

	#include "ast/lexproto.h"
	#include "ast/parseexception.h"

#line 58 "bison.cc" // lalr1.cc:413


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
#line 144 "bison.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  BisonParser::yytnamerr_ (const char *yystr)
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
  BisonParser::BisonParser (const std::string &filename_yyarg, RootAst *result_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      filename (filename_yyarg),
      result (result_yyarg)
  {}

  BisonParser::~BisonParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  BisonParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  BisonParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  BisonParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  BisonParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  BisonParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  BisonParser::symbol_number_type
  BisonParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  BisonParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  BisonParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 23: // class
      case 25: // method
      case 28: // decl_param
      case 30: // stmt
      case 31: // expr
      case 32: // name
      case 33: // new_name
      case 36: // decl_stmt
      case 38: // decl_bean
      case 39: // type
      case 40: // return_stmt
      case 41: // while_stmt
      case 42: // do_while_stmt
        value.move< Ast* > (that.value);
        break;

      case 22: // class_list
      case 24: // method_list
      case 26: // param_list
      case 27: // param_list_noemp
      case 29: // stmt_list
      case 34: // arg_list
      case 35: // arg_list_noemp
      case 37: // decl_bean_list
        value.move< ListAst* > (that.value);
        break;

      case 19: // "identifier"
      case 20: // "number"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  BisonParser::stack_symbol_type&
  BisonParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 23: // class
      case 25: // method
      case 28: // decl_param
      case 30: // stmt
      case 31: // expr
      case 32: // name
      case 33: // new_name
      case 36: // decl_stmt
      case 38: // decl_bean
      case 39: // type
      case 40: // return_stmt
      case 41: // while_stmt
      case 42: // do_while_stmt
        value.copy< Ast* > (that.value);
        break;

      case 22: // class_list
      case 24: // method_list
      case 26: // param_list
      case 27: // param_list_noemp
      case 29: // stmt_list
      case 34: // arg_list
      case 35: // arg_list_noemp
      case 37: // decl_bean_list
        value.copy< ListAst* > (that.value);
        break;

      case 19: // "identifier"
      case 20: // "number"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  BisonParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  BisonParser::yy_print_ (std::ostream& yyo,
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
    switch (yytype)
    {
            case 19: // "identifier"

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 376 "bison.cc" // lalr1.cc:636
        break;

      case 20: // "number"

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 383 "bison.cc" // lalr1.cc:636
        break;

      case 22: // class_list

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 390 "bison.cc" // lalr1.cc:636
        break;

      case 23: // class

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 397 "bison.cc" // lalr1.cc:636
        break;

      case 24: // method_list

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 404 "bison.cc" // lalr1.cc:636
        break;

      case 25: // method

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 411 "bison.cc" // lalr1.cc:636
        break;

      case 26: // param_list

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 418 "bison.cc" // lalr1.cc:636
        break;

      case 27: // param_list_noemp

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 425 "bison.cc" // lalr1.cc:636
        break;

      case 28: // decl_param

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 432 "bison.cc" // lalr1.cc:636
        break;

      case 29: // stmt_list

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 439 "bison.cc" // lalr1.cc:636
        break;

      case 30: // stmt

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 446 "bison.cc" // lalr1.cc:636
        break;

      case 31: // expr

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 453 "bison.cc" // lalr1.cc:636
        break;

      case 32: // name

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 460 "bison.cc" // lalr1.cc:636
        break;

      case 33: // new_name

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 467 "bison.cc" // lalr1.cc:636
        break;

      case 34: // arg_list

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 474 "bison.cc" // lalr1.cc:636
        break;

      case 35: // arg_list_noemp

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 481 "bison.cc" // lalr1.cc:636
        break;

      case 36: // decl_stmt

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 488 "bison.cc" // lalr1.cc:636
        break;

      case 37: // decl_bean_list

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ListAst* > (); }
#line 495 "bison.cc" // lalr1.cc:636
        break;

      case 38: // decl_bean

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 502 "bison.cc" // lalr1.cc:636
        break;

      case 39: // type

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 509 "bison.cc" // lalr1.cc:636
        break;

      case 40: // return_stmt

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 516 "bison.cc" // lalr1.cc:636
        break;

      case 41: // while_stmt

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 523 "bison.cc" // lalr1.cc:636
        break;

      case 42: // do_while_stmt

#line 94 "bison.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Ast* > (); }
#line 530 "bison.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  BisonParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  BisonParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  BisonParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  BisonParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  BisonParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  BisonParser::debug_level_type
  BisonParser::debug_level () const
  {
    return yydebug_;
  }

  void
  BisonParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline BisonParser::state_type
  BisonParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  BisonParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  BisonParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  BisonParser::parse ()
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
    #line 29 "bison.yy" // lalr1.cc:741
{
	/* Initialize the initial location. */ 
	/* position.filename is a non-const pointer somehow */
	static std::string s_filename(filename);
	yyla.location.begin.filename = yyla.location.end.filename = &s_filename;
}

#line 651 "bison.cc" // lalr1.cc:741

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
            symbol_type yylookahead (yylex (filename, result));
            yyla.move (yylookahead);
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 23: // class
      case 25: // method
      case 28: // decl_param
      case 30: // stmt
      case 31: // expr
      case 32: // name
      case 33: // new_name
      case 36: // decl_stmt
      case 38: // decl_bean
      case 39: // type
      case 40: // return_stmt
      case 41: // while_stmt
      case 42: // do_while_stmt
        yylhs.value.build< Ast* > ();
        break;

      case 22: // class_list
      case 24: // method_list
      case 26: // param_list
      case 27: // param_list_noemp
      case 29: // stmt_list
      case 34: // arg_list
      case 35: // arg_list_noemp
      case 37: // decl_bean_list
        yylhs.value.build< ListAst* > ();
        break;

      case 19: // "identifier"
      case 20: // "number"
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


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
#line 104 "bison.yy" // lalr1.cc:859
    { /* already newwed as 'result' */ }
#line 793 "bison.cc" // lalr1.cc:859
    break;

  case 3:
#line 105 "bison.yy" // lalr1.cc:859
    { result->append(yystack_[0].value.as< Ast* > ()); }
#line 799 "bison.cc" // lalr1.cc:859
    break;

  case 4:
#line 109 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<2>(Ast::Type::CLASS, yystack_[3].value.as< Ast* > (), yystack_[1].value.as< ListAst* > ()); }
#line 805 "bison.cc" // lalr1.cc:859
    break;

  case 5:
#line 113 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = new ListAst(Ast::Type::METHOD_LIST); }
#line 811 "bison.cc" // lalr1.cc:859
    break;

  case 6:
#line 115 "bison.yy" // lalr1.cc:859
    { yystack_[1].value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); yylhs.value.as< ListAst* > () = yystack_[1].value.as< ListAst* > (); }
#line 817 "bison.cc" // lalr1.cc:859
    break;

  case 7:
#line 119 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<3>(Ast::Type::METHOD, yystack_[6].value.as< Ast* > (), yystack_[4].value.as< ListAst* > (), yystack_[1].value.as< ListAst* > ()); }
#line 823 "bison.cc" // lalr1.cc:859
    break;

  case 8:
#line 123 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = new ListAst(Ast::Type::DECL_PARAM_LIST); }
#line 829 "bison.cc" // lalr1.cc:859
    break;

  case 9:
#line 125 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = yystack_[0].value.as< ListAst* > (); }
#line 835 "bison.cc" // lalr1.cc:859
    break;

  case 10:
#line 128 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = new ListAst(Ast::Type::DECL_PARAM_LIST); 
				  yylhs.value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); }
#line 842 "bison.cc" // lalr1.cc:859
    break;

  case 11:
#line 131 "bison.yy" // lalr1.cc:859
    { yystack_[2].value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); yylhs.value.as< ListAst* > () = yystack_[2].value.as< ListAst* > (); }
#line 848 "bison.cc" // lalr1.cc:859
    break;

  case 12:
#line 135 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<2>(Ast::Type::DECL_PARAM, yystack_[1].value.as< Ast* > (), yystack_[0].value.as< Ast* > ()); }
#line 854 "bison.cc" // lalr1.cc:859
    break;

  case 13:
#line 139 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = new ListAst(Ast::Type::STMT_LIST); }
#line 860 "bison.cc" // lalr1.cc:859
    break;

  case 14:
#line 141 "bison.yy" // lalr1.cc:859
    { yystack_[1].value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); yylhs.value.as< ListAst* > () = yystack_[1].value.as< ListAst* > (); }
#line 866 "bison.cc" // lalr1.cc:859
    break;

  case 15:
#line 145 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[1].value.as< Ast* > (); }
#line 872 "bison.cc" // lalr1.cc:859
    break;

  case 16:
#line 147 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[0].value.as< Ast* > (); }
#line 878 "bison.cc" // lalr1.cc:859
    break;

  case 17:
#line 149 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[0].value.as< Ast* > (); }
#line 884 "bison.cc" // lalr1.cc:859
    break;

  case 18:
#line 151 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[0].value.as< Ast* > (); }
#line 890 "bison.cc" // lalr1.cc:859
    break;

  case 19:
#line 153 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[0].value.as< Ast* > (); }
#line 896 "bison.cc" // lalr1.cc:859
    break;

  case 20:
#line 155 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[1].value.as< ListAst* > (); }
#line 902 "bison.cc" // lalr1.cc:859
    break;

  case 21:
#line 162 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = TermListAst::makeBop(yystack_[2].value.as< Ast* > (), yystack_[0].value.as< Ast* > (), TermListAst::Op::ADD); }
#line 908 "bison.cc" // lalr1.cc:859
    break;

  case 22:
#line 164 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = TermListAst::makeBop(yystack_[2].value.as< Ast* > (), yystack_[0].value.as< Ast* > (), TermListAst::Op::SUB); }
#line 914 "bison.cc" // lalr1.cc:859
    break;

  case 23:
#line 166 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = TermListAst::makeBop(yystack_[2].value.as< Ast* > (), yystack_[0].value.as< Ast* > (), TermListAst::Op::MUL); }
#line 920 "bison.cc" // lalr1.cc:859
    break;

  case 24:
#line 168 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = TermListAst::makeBop(yystack_[2].value.as< Ast* > (), yystack_[0].value.as< Ast* > (), TermListAst::Op::DIV); }
#line 926 "bison.cc" // lalr1.cc:859
    break;

  case 25:
#line 170 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<2>(Ast::Type::ASSIGN, yystack_[2].value.as< Ast* > (), yystack_[0].value.as< Ast* > ()); }
#line 932 "bison.cc" // lalr1.cc:859
    break;

  case 26:
#line 172 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<2>(Ast::Type::CALL, yystack_[3].value.as< Ast* > (), yystack_[1].value.as< ListAst* > ()); }
#line 938 "bison.cc" // lalr1.cc:859
    break;

  case 27:
#line 174 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<1>(Ast::Type::PAREN, yystack_[1].value.as< Ast* > ()); }
#line 944 "bison.cc" // lalr1.cc:859
    break;

  case 28:
#line 176 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[0].value.as< Ast* > (); }
#line 950 "bison.cc" // lalr1.cc:859
    break;

  case 29:
#line 178 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new ScalarAst(Ast::Type::NUMBER, yystack_[0].value.as< std::string > ()); }
#line 956 "bison.cc" // lalr1.cc:859
    break;

  case 30:
#line 182 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new ScalarAst(Ast::Type::IDENT, yystack_[0].value.as< std::string > ()); }
#line 962 "bison.cc" // lalr1.cc:859
    break;

  case 31:
#line 186 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new ScalarAst(Ast::Type::IDENT, yystack_[0].value.as< std::string > ()); }
#line 968 "bison.cc" // lalr1.cc:859
    break;

  case 32:
#line 190 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = new ListAst(Ast::Type::ARG_LIST); }
#line 974 "bison.cc" // lalr1.cc:859
    break;

  case 33:
#line 192 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = yystack_[0].value.as< ListAst* > (); }
#line 980 "bison.cc" // lalr1.cc:859
    break;

  case 34:
#line 196 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = new ListAst(Ast::Type::ARG_LIST); yylhs.value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); }
#line 986 "bison.cc" // lalr1.cc:859
    break;

  case 35:
#line 198 "bison.yy" // lalr1.cc:859
    { yystack_[2].value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); yylhs.value.as< ListAst* > () = yystack_[2].value.as< ListAst* > (); }
#line 992 "bison.cc" // lalr1.cc:859
    break;

  case 36:
#line 202 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<2>(Ast::Type::DECL, yystack_[2].value.as< Ast* > (), yystack_[1].value.as< ListAst* > ()); }
#line 998 "bison.cc" // lalr1.cc:859
    break;

  case 37:
#line 206 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< ListAst* > () = new ListAst(Ast::Type::DECL_BEAN_LIST); 
				  yylhs.value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); }
#line 1005 "bison.cc" // lalr1.cc:859
    break;

  case 38:
#line 209 "bison.yy" // lalr1.cc:859
    { yystack_[2].value.as< ListAst* > ()->append(yystack_[0].value.as< Ast* > ()); yylhs.value.as< ListAst* > () = yystack_[2].value.as< ListAst* > (); }
#line 1011 "bison.cc" // lalr1.cc:859
    break;

  case 39:
#line 213 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new DeclBeanAst(yystack_[0].value.as< Ast* > ()); }
#line 1017 "bison.cc" // lalr1.cc:859
    break;

  case 40:
#line 215 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new DeclBeanAst(yystack_[2].value.as< Ast* > (), yystack_[0].value.as< Ast* > ()); }
#line 1023 "bison.cc" // lalr1.cc:859
    break;

  case 41:
#line 219 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = yystack_[0].value.as< Ast* > (); }
#line 1029 "bison.cc" // lalr1.cc:859
    break;

  case 42:
#line 223 "bison.yy" // lalr1.cc:859
    { yylhs.value.as< Ast* > () = new FixSizeAst<1>(Ast::Type::RETURN, yystack_[1].value.as< Ast* > ()); }
#line 1035 "bison.cc" // lalr1.cc:859
    break;

  case 43:
#line 226 "bison.yy" // lalr1.cc:859
    { ListAst *body;
				  if (yystack_[0].value.as< Ast* > ()->getType() == Ast::Type::STMT_LIST) {
				  	body = &yystack_[0].value.as< Ast* > ()->asList();
				  } else {
				  	body = new ListAst(Ast::Type::STMT_LIST);;
					body->append(yystack_[0].value.as< Ast* > ());
				  }
				  yylhs.value.as< Ast* > () = new FixSizeAst<2>(Ast::Type::WHILE, yystack_[2].value.as< Ast* > (), body); }
#line 1048 "bison.cc" // lalr1.cc:859
    break;

  case 44:
#line 236 "bison.yy" // lalr1.cc:859
    { ListAst *body;
				  if (yystack_[5].value.as< Ast* > ()->getType() == Ast::Type::STMT_LIST) {
				  	body = &yystack_[5].value.as< Ast* > ()->asList();
				  } else {
				  	body = new ListAst(Ast::Type::STMT_LIST);;
					body->append(yystack_[5].value.as< Ast* > ());
				  }
				  yylhs.value.as< Ast* > () = new FixSizeAst<2>(Ast::Type::DO_WHILE, body, yystack_[2].value.as< Ast* > ()); }
#line 1061 "bison.cc" // lalr1.cc:859
    break;


#line 1065 "bison.cc" // lalr1.cc:859
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
  BisonParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  BisonParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char BisonParser::yypact_ninf_ = -27;

  const signed char BisonParser::yytable_ninf_ = -42;

  const signed char
  BisonParser::yypact_[] =
  {
     -27,     5,   -27,   -12,   -27,   -27,    12,   -27,    -5,   -12,
     -27,   -27,    -7,     1,   -27,    25,    36,   -27,   -27,   -12,
      37,     1,   -27,   -27,   -27,    55,    -3,    42,    77,   -27,
     -27,    -3,   -27,   -27,    95,    27,   -27,   -12,   -27,   -27,
     -27,   100,    44,    -3,    53,    66,    30,    -3,    -3,    -3,
      -3,    -3,   -27,    -3,    65,    17,   -27,   -27,    35,    62,
     -27,   -27,   111,    56,    56,   -27,   -27,   111,    72,    59,
      -3,   -27,   -12,    77,    -3,   -27,    -3,   111,   -27,   -27,
      51,   111,    67,   -27
  };

  const unsigned char
  BisonParser::yydefact_[] =
  {
       2,     0,     1,     0,     3,    31,     0,     5,     0,     0,
       4,     6,     0,     8,    30,     0,     9,    10,    41,     0,
       0,     0,    12,    13,    11,     0,     0,     0,     0,    13,
       7,     0,    29,    14,     0,    28,    16,     0,    17,    18,
      19,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    32,    39,     0,    37,    42,     0,     0,
      20,    27,    25,    22,    21,    23,    24,    34,     0,    33,
       0,    36,     0,     0,     0,    26,     0,    40,    38,    43,
       0,    35,     0,    44
  };

  const signed char
  BisonParser::yypgoto_[] =
  {
     -27,   -27,   -27,   -27,   -27,   -27,   -27,    63,    64,   -26,
     -25,   -13,     0,   -27,   -27,   -27,   -27,    19,     8,   -27,
     -27,   -27
  };

  const signed char
  BisonParser::yydefgoto_[] =
  {
      -1,     1,     4,     8,    11,    15,    16,    17,    25,    33,
      34,    42,    54,    68,    69,    36,    55,    56,    37,    38,
      39,    40
  };

  const signed char
  BisonParser::yytable_[] =
  {
      18,    41,    44,     6,     9,     2,    46,     5,    18,    12,
      13,    10,    35,     3,    31,    35,    14,    32,    58,    22,
      14,    19,    62,    63,    64,    65,    66,     7,    67,    19,
      71,    72,    35,    47,    48,    49,    50,    51,    47,    48,
      49,    50,    51,    20,    53,    77,   -41,    79,    61,    80,
      21,    81,    23,    73,    47,    48,    49,    50,    51,    43,
      35,    53,    50,    51,    59,    26,    27,    28,    70,    82,
      29,    30,    31,    76,    14,    32,    26,    27,    28,    74,
      83,    29,    60,    31,    24,    14,    32,    26,    27,    28,
      75,    78,    29,    45,    31,     0,    14,    32,    47,    48,
      49,    50,    51,    47,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    57,    47,    48,    49,    50,    51
  };

  const signed char
  BisonParser::yycheck_[] =
  {
      13,    26,    28,     3,     9,     0,    31,    19,    21,     9,
      17,    16,    25,     8,    17,    28,    19,    20,    43,    19,
      19,    13,    47,    48,    49,    50,    51,    15,    53,    21,
      13,    14,    45,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    18,    17,    70,    19,    73,    18,    74,
      14,    76,    15,    18,     3,     4,     5,     6,     7,    17,
      73,    17,     6,     7,    11,    10,    11,    12,     3,    18,
      15,    16,    17,    14,    19,    20,    10,    11,    12,    17,
      13,    15,    16,    17,    21,    19,    20,    10,    11,    12,
      18,    72,    15,    29,    17,    -1,    19,    20,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    13,    -1,
      -1,    -1,    -1,    13,     3,     4,     5,     6,     7
  };

  const unsigned char
  BisonParser::yystos_[] =
  {
       0,    22,     0,     8,    23,    19,    33,    15,    24,     9,
      16,    25,    33,    17,    19,    26,    27,    28,    32,    39,
      18,    14,    33,    15,    28,    29,    10,    11,    12,    15,
      16,    17,    20,    30,    31,    32,    36,    39,    40,    41,
      42,    31,    32,    17,    30,    29,    31,     3,     4,     5,
       6,     7,    13,    17,    33,    37,    38,    13,    31,    11,
      16,    18,    31,    31,    31,    31,    31,    31,    34,    35,
       3,    13,    14,    18,    17,    18,    14,    31,    38,    30,
      31,    31,    18,    13
  };

  const unsigned char
  BisonParser::yyr1_[] =
  {
       0,    21,    22,    22,    23,    24,    24,    25,    26,    26,
      27,    27,    28,    29,    29,    30,    30,    30,    30,    30,
      30,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      32,    33,    34,    34,    35,    35,    36,    37,    37,    38,
      38,    39,    40,    41,    42
  };

  const unsigned char
  BisonParser::yyr2_[] =
  {
       0,     2,     0,     2,     5,     0,     2,     8,     0,     1,
       1,     3,     2,     0,     2,     2,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     4,     3,     1,     1,
       1,     1,     0,     1,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     5,     7
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const BisonParser::yytname_[] =
  {
  "\"EOF\"", "error", "$undefined", "\"=\"", "\"-\"", "\"+\"", "\"*\"",
  "\"/\"", "\"class\"", "\"void\"", "\"return\"", "\"while\"", "\"do\"",
  "\";\"", "\",\"", "\"{\"", "\"}\"", "\"(\"", "\")\"", "\"identifier\"",
  "\"number\"", "$accept", "class_list", "class", "method_list", "method",
  "param_list", "param_list_noemp", "decl_param", "stmt_list", "stmt",
  "expr", "name", "new_name", "arg_list", "arg_list_noemp", "decl_stmt",
  "decl_bean_list", "decl_bean", "type", "return_stmt", "while_stmt",
  "do_while_stmt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  BisonParser::yyrline_[] =
  {
       0,   104,   104,   105,   108,   112,   114,   118,   122,   124,
     127,   130,   134,   138,   140,   144,   146,   148,   150,   152,
     154,   161,   163,   165,   167,   169,   171,   173,   175,   177,
     181,   185,   189,   191,   195,   197,   201,   205,   208,   212,
     214,   218,   222,   225,   235
  };

  // Print the state stack on the debug stream.
  void
  BisonParser::yystack_print_ ()
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
  BisonParser::yy_reduce_print_ (int yyrule)
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



} // yy
#line 1496 "bison.cc" // lalr1.cc:1167
#line 245 "bison.yy" // lalr1.cc:1168


void yy::BisonParser::error(const location_type& l,
                              const std::string& m)
{
	throw ParseException(l, m);
}

