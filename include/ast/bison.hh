// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file bison.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_BISON_HH_INCLUDED
# define YY_YY_BISON_HH_INCLUDED
// //                    "%code requires" blocks.
#line 11 "bison.yy" // lalr1.cc:377

	#include <string>
	#include "ast/ast.h"
	#include "ast/scalarast.h"
	#include "ast/fixsizeast.h"
	#include "ast/listast.h"
	#include "ast/boplistast.h"
	#include "ast/rootast.h"
	class ParseException;

#line 55 "bison.hh" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 132 "bison.hh" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class BisonParser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // type_spec
      // type_name
      // ptype
      // class
      // decl_method
      // decl_param
      // stmt
      // ident
      // decl_var
      // dector
      // dector_name
      // jump_stmt
      // while_stmt
      // do_while_stmt
      // for_stmt
      // for_init
      // catch
      // expr
      // expr_lv0
      // expr_lv1
      // expr_lv2
      // expr_lv3
      // expr_lv4
      // expr_lv5
      // expr_lv6
      // expr_lv7
      // expr_lv8
      // expr_lv9
      // expr_lv10
      // expr_lv11
      // expr_lv12
      // expr_ptype
      // expr_unary
      // expr_unary_logic
      // expr_pp
      // expr_post
      // expr_prime
      // expr_prime_noname
      // expr_prime_cx
      // expr_prime_cx_nude
      // expr_call
      // expr_field
      // expr_new
      // expr_new_plain
      // callee
      // name
      // special_name
      char dummy1[sizeof(Ast*)];

      // class_list
      // member_list
      // param_list
      // param_list_noemp
      // stmt_list
      // arg_list
      // arg_list_noemp
      // dector_list
      // try_list
      // catch_list
      // if_list
      // name_list
      char dummy2[sizeof(ListAst*)];

      // modifiers
      // modifier
      char dummy3[sizeof(Modifiers)];

      // dims
      char dummy4[sizeof(int)];

      // "identifier"
      // "number"
      // "string"
      // "void"
      char dummy5[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_END = 0,
        TOK_CLASS = 258,
        TOK_INTERFACE = 259,
        TOK_EXTENDS = 260,
        TOK_IMPLEMENTS = 261,
        TOK_WHILE = 262,
        TOK_DO = 263,
        TOK_FOR = 264,
        TOK_IF = 265,
        TOK_ELSE = 266,
        TOK_RETURN = 267,
        TOK_BREAK = 268,
        TOK_CONTINUE = 269,
        TOK_THROW = 270,
        TOK_THROWS = 271,
        TOK_INSTANCEOF = 272,
        TOK_JNULL = 273,
        TOK_THIS = 274,
        TOK_SUPER = 275,
        TOK_NEW = 276,
        TOK_TRY = 277,
        TOK_CATCH = 278,
        TOK_FINALLY = 279,
        TOK_ABSTRACT = 280,
        TOK_FINAL = 281,
        TOK_PUBLIC = 282,
        TOK_PROTECTED = 283,
        TOK_PRIVATE = 284,
        TOK_STATIC = 285,
        TOK_TRANSIENT = 286,
        TOK_VOLATILE = 287,
        TOK_NATIVE = 288,
        TOK_SYNCHRONIZED = 289,
        TOK_ASSIGN = 290,
        TOK_ASS_SUB = 291,
        TOK_ASS_ADD = 292,
        TOK_ASS_MUL = 293,
        TOK_ASS_DIV = 294,
        TOK_ASS_MOD = 295,
        TOK_ASS_AND = 296,
        TOK_ASS_XOR = 297,
        TOK_ASS_OR = 298,
        TOK_ASS_SHL = 299,
        TOK_ASS_SHR = 300,
        TOK_ASS_SHRA = 301,
        TOK_SUB = 302,
        TOK_ADD = 303,
        TOK_MUL = 304,
        TOK_DIV = 305,
        TOK_MOD = 306,
        TOK_COLON = 307,
        TOK_QUESTION = 308,
        TOK_SEMICOLON = 309,
        TOK_DOT = 310,
        TOK_COMMA = 311,
        TOK_LBRACE = 312,
        TOK_RBRACE = 313,
        TOK_LSQUARE = 314,
        TOK_RSQUARE = 315,
        TOK_LPAREN = 316,
        TOK_RPAREN = 317,
        TOK_LOGIC_OR = 318,
        TOK_LOGIC_AND = 319,
        TOK_LOGIC_NOT = 320,
        TOK_BIT_OR = 321,
        TOK_BIT_AND = 322,
        TOK_BIT_XOR = 323,
        TOK_BIT_NOT = 324,
        TOK_EQ = 325,
        TOK_NEQ = 326,
        TOK_LT = 327,
        TOK_GT = 328,
        TOK_LEQ = 329,
        TOK_GEQ = 330,
        TOK_SHL = 331,
        TOK_SHR = 332,
        TOK_SHRA = 333,
        TOK_INC = 334,
        TOK_DEC = 335,
        TOK_DIM = 336,
        TOK_IDENTIFIER = 337,
        TOK_NUMBER = 338,
        TOK_STRING = 339,
        TOK_VOID = 340
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const Ast* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ListAst* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const Modifiers v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const int v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_CLASS (const location_type& l);

    static inline
    symbol_type
    make_INTERFACE (const location_type& l);

    static inline
    symbol_type
    make_EXTENDS (const location_type& l);

    static inline
    symbol_type
    make_IMPLEMENTS (const location_type& l);

    static inline
    symbol_type
    make_WHILE (const location_type& l);

    static inline
    symbol_type
    make_DO (const location_type& l);

    static inline
    symbol_type
    make_FOR (const location_type& l);

    static inline
    symbol_type
    make_IF (const location_type& l);

    static inline
    symbol_type
    make_ELSE (const location_type& l);

    static inline
    symbol_type
    make_RETURN (const location_type& l);

    static inline
    symbol_type
    make_BREAK (const location_type& l);

    static inline
    symbol_type
    make_CONTINUE (const location_type& l);

    static inline
    symbol_type
    make_THROW (const location_type& l);

    static inline
    symbol_type
    make_THROWS (const location_type& l);

    static inline
    symbol_type
    make_INSTANCEOF (const location_type& l);

    static inline
    symbol_type
    make_JNULL (const location_type& l);

    static inline
    symbol_type
    make_THIS (const location_type& l);

    static inline
    symbol_type
    make_SUPER (const location_type& l);

    static inline
    symbol_type
    make_NEW (const location_type& l);

    static inline
    symbol_type
    make_TRY (const location_type& l);

    static inline
    symbol_type
    make_CATCH (const location_type& l);

    static inline
    symbol_type
    make_FINALLY (const location_type& l);

    static inline
    symbol_type
    make_ABSTRACT (const location_type& l);

    static inline
    symbol_type
    make_FINAL (const location_type& l);

    static inline
    symbol_type
    make_PUBLIC (const location_type& l);

    static inline
    symbol_type
    make_PROTECTED (const location_type& l);

    static inline
    symbol_type
    make_PRIVATE (const location_type& l);

    static inline
    symbol_type
    make_STATIC (const location_type& l);

    static inline
    symbol_type
    make_TRANSIENT (const location_type& l);

    static inline
    symbol_type
    make_VOLATILE (const location_type& l);

    static inline
    symbol_type
    make_NATIVE (const location_type& l);

    static inline
    symbol_type
    make_SYNCHRONIZED (const location_type& l);

    static inline
    symbol_type
    make_ASSIGN (const location_type& l);

    static inline
    symbol_type
    make_ASS_SUB (const location_type& l);

    static inline
    symbol_type
    make_ASS_ADD (const location_type& l);

    static inline
    symbol_type
    make_ASS_MUL (const location_type& l);

    static inline
    symbol_type
    make_ASS_DIV (const location_type& l);

    static inline
    symbol_type
    make_ASS_MOD (const location_type& l);

    static inline
    symbol_type
    make_ASS_AND (const location_type& l);

    static inline
    symbol_type
    make_ASS_XOR (const location_type& l);

    static inline
    symbol_type
    make_ASS_OR (const location_type& l);

    static inline
    symbol_type
    make_ASS_SHL (const location_type& l);

    static inline
    symbol_type
    make_ASS_SHR (const location_type& l);

    static inline
    symbol_type
    make_ASS_SHRA (const location_type& l);

    static inline
    symbol_type
    make_SUB (const location_type& l);

    static inline
    symbol_type
    make_ADD (const location_type& l);

    static inline
    symbol_type
    make_MUL (const location_type& l);

    static inline
    symbol_type
    make_DIV (const location_type& l);

    static inline
    symbol_type
    make_MOD (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_QUESTION (const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const location_type& l);

    static inline
    symbol_type
    make_DOT (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_LBRACE (const location_type& l);

    static inline
    symbol_type
    make_RBRACE (const location_type& l);

    static inline
    symbol_type
    make_LSQUARE (const location_type& l);

    static inline
    symbol_type
    make_RSQUARE (const location_type& l);

    static inline
    symbol_type
    make_LPAREN (const location_type& l);

    static inline
    symbol_type
    make_RPAREN (const location_type& l);

    static inline
    symbol_type
    make_LOGIC_OR (const location_type& l);

    static inline
    symbol_type
    make_LOGIC_AND (const location_type& l);

    static inline
    symbol_type
    make_LOGIC_NOT (const location_type& l);

    static inline
    symbol_type
    make_BIT_OR (const location_type& l);

    static inline
    symbol_type
    make_BIT_AND (const location_type& l);

    static inline
    symbol_type
    make_BIT_XOR (const location_type& l);

    static inline
    symbol_type
    make_BIT_NOT (const location_type& l);

    static inline
    symbol_type
    make_EQ (const location_type& l);

    static inline
    symbol_type
    make_NEQ (const location_type& l);

    static inline
    symbol_type
    make_LT (const location_type& l);

    static inline
    symbol_type
    make_GT (const location_type& l);

    static inline
    symbol_type
    make_LEQ (const location_type& l);

    static inline
    symbol_type
    make_GEQ (const location_type& l);

    static inline
    symbol_type
    make_SHL (const location_type& l);

    static inline
    symbol_type
    make_SHR (const location_type& l);

    static inline
    symbol_type
    make_SHRA (const location_type& l);

    static inline
    symbol_type
    make_INC (const location_type& l);

    static inline
    symbol_type
    make_DEC (const location_type& l);

    static inline
    symbol_type
    make_DIM (const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_NUMBER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_STRING (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_VOID (const std::string& v, const location_type& l);


    /// Build a parser object.
    BisonParser (const std::string &filename_yyarg, RootAst *result_yyarg);
    virtual ~BisonParser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    BisonParser (const BisonParser&);
    BisonParser& operator= (const BisonParser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const short int yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 1889,     ///< Last index in yytable_.
      yynnts_ = 63,  ///< Number of nonterminal symbols.
      yyfinal_ = 2, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 87  ///< Number of tokens.
    };


    // User arguments.
    const std::string &filename;
    RootAst *result;
  };

  // Symbol number corresponding to token number t.
  inline
  BisonParser::token_number_type
  BisonParser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
    };
    const unsigned int user_token_number_max_ = 341;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  BisonParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  BisonParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  BisonParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 88: // type_spec
      case 89: // type_name
      case 90: // ptype
      case 94: // class
      case 96: // decl_method
      case 99: // decl_param
      case 101: // stmt
      case 102: // ident
      case 105: // decl_var
      case 107: // dector
      case 108: // dector_name
      case 109: // jump_stmt
      case 110: // while_stmt
      case 111: // do_while_stmt
      case 112: // for_stmt
      case 113: // for_init
      case 116: // catch
      case 118: // expr
      case 119: // expr_lv0
      case 120: // expr_lv1
      case 121: // expr_lv2
      case 122: // expr_lv3
      case 123: // expr_lv4
      case 124: // expr_lv5
      case 125: // expr_lv6
      case 126: // expr_lv7
      case 127: // expr_lv8
      case 128: // expr_lv9
      case 129: // expr_lv10
      case 130: // expr_lv11
      case 131: // expr_lv12
      case 132: // expr_ptype
      case 133: // expr_unary
      case 134: // expr_unary_logic
      case 135: // expr_pp
      case 136: // expr_post
      case 137: // expr_prime
      case 138: // expr_prime_noname
      case 139: // expr_prime_cx
      case 140: // expr_prime_cx_nude
      case 141: // expr_call
      case 142: // expr_field
      case 143: // expr_new
      case 144: // expr_new_plain
      case 145: // callee
      case 146: // name
      case 148: // special_name
        value.copy< Ast* > (other.value);
        break;

      case 93: // class_list
      case 95: // member_list
      case 97: // param_list
      case 98: // param_list_noemp
      case 100: // stmt_list
      case 103: // arg_list
      case 104: // arg_list_noemp
      case 106: // dector_list
      case 114: // try_list
      case 115: // catch_list
      case 117: // if_list
      case 147: // name_list
        value.copy< ListAst* > (other.value);
        break;

      case 91: // modifiers
      case 92: // modifier
        value.copy< Modifiers > (other.value);
        break;

      case 149: // dims
        value.copy< int > (other.value);
        break;

      case 82: // "identifier"
      case 83: // "number"
      case 84: // "string"
      case 85: // "void"
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  BisonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 88: // type_spec
      case 89: // type_name
      case 90: // ptype
      case 94: // class
      case 96: // decl_method
      case 99: // decl_param
      case 101: // stmt
      case 102: // ident
      case 105: // decl_var
      case 107: // dector
      case 108: // dector_name
      case 109: // jump_stmt
      case 110: // while_stmt
      case 111: // do_while_stmt
      case 112: // for_stmt
      case 113: // for_init
      case 116: // catch
      case 118: // expr
      case 119: // expr_lv0
      case 120: // expr_lv1
      case 121: // expr_lv2
      case 122: // expr_lv3
      case 123: // expr_lv4
      case 124: // expr_lv5
      case 125: // expr_lv6
      case 126: // expr_lv7
      case 127: // expr_lv8
      case 128: // expr_lv9
      case 129: // expr_lv10
      case 130: // expr_lv11
      case 131: // expr_lv12
      case 132: // expr_ptype
      case 133: // expr_unary
      case 134: // expr_unary_logic
      case 135: // expr_pp
      case 136: // expr_post
      case 137: // expr_prime
      case 138: // expr_prime_noname
      case 139: // expr_prime_cx
      case 140: // expr_prime_cx_nude
      case 141: // expr_call
      case 142: // expr_field
      case 143: // expr_new
      case 144: // expr_new_plain
      case 145: // callee
      case 146: // name
      case 148: // special_name
        value.copy< Ast* > (v);
        break;

      case 93: // class_list
      case 95: // member_list
      case 97: // param_list
      case 98: // param_list_noemp
      case 100: // stmt_list
      case 103: // arg_list
      case 104: // arg_list_noemp
      case 106: // dector_list
      case 114: // try_list
      case 115: // catch_list
      case 117: // if_list
      case 147: // name_list
        value.copy< ListAst* > (v);
        break;

      case 91: // modifiers
      case 92: // modifier
        value.copy< Modifiers > (v);
        break;

      case 149: // dims
        value.copy< int > (v);
        break;

      case 82: // "identifier"
      case 83: // "number"
      case 84: // "string"
      case 85: // "void"
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  BisonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  BisonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Ast* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  BisonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ListAst* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  BisonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Modifiers v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  BisonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  BisonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  BisonParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  BisonParser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 88: // type_spec
      case 89: // type_name
      case 90: // ptype
      case 94: // class
      case 96: // decl_method
      case 99: // decl_param
      case 101: // stmt
      case 102: // ident
      case 105: // decl_var
      case 107: // dector
      case 108: // dector_name
      case 109: // jump_stmt
      case 110: // while_stmt
      case 111: // do_while_stmt
      case 112: // for_stmt
      case 113: // for_init
      case 116: // catch
      case 118: // expr
      case 119: // expr_lv0
      case 120: // expr_lv1
      case 121: // expr_lv2
      case 122: // expr_lv3
      case 123: // expr_lv4
      case 124: // expr_lv5
      case 125: // expr_lv6
      case 126: // expr_lv7
      case 127: // expr_lv8
      case 128: // expr_lv9
      case 129: // expr_lv10
      case 130: // expr_lv11
      case 131: // expr_lv12
      case 132: // expr_ptype
      case 133: // expr_unary
      case 134: // expr_unary_logic
      case 135: // expr_pp
      case 136: // expr_post
      case 137: // expr_prime
      case 138: // expr_prime_noname
      case 139: // expr_prime_cx
      case 140: // expr_prime_cx_nude
      case 141: // expr_call
      case 142: // expr_field
      case 143: // expr_new
      case 144: // expr_new_plain
      case 145: // callee
      case 146: // name
      case 148: // special_name
        value.template destroy< Ast* > ();
        break;

      case 93: // class_list
      case 95: // member_list
      case 97: // param_list
      case 98: // param_list_noemp
      case 100: // stmt_list
      case 103: // arg_list
      case 104: // arg_list_noemp
      case 106: // dector_list
      case 114: // try_list
      case 115: // catch_list
      case 117: // if_list
      case 147: // name_list
        value.template destroy< ListAst* > ();
        break;

      case 91: // modifiers
      case 92: // modifier
        value.template destroy< Modifiers > ();
        break;

      case 149: // dims
        value.template destroy< int > ();
        break;

      case 82: // "identifier"
      case 83: // "number"
      case 84: // "string"
      case 85: // "void"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  BisonParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  BisonParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 88: // type_spec
      case 89: // type_name
      case 90: // ptype
      case 94: // class
      case 96: // decl_method
      case 99: // decl_param
      case 101: // stmt
      case 102: // ident
      case 105: // decl_var
      case 107: // dector
      case 108: // dector_name
      case 109: // jump_stmt
      case 110: // while_stmt
      case 111: // do_while_stmt
      case 112: // for_stmt
      case 113: // for_init
      case 116: // catch
      case 118: // expr
      case 119: // expr_lv0
      case 120: // expr_lv1
      case 121: // expr_lv2
      case 122: // expr_lv3
      case 123: // expr_lv4
      case 124: // expr_lv5
      case 125: // expr_lv6
      case 126: // expr_lv7
      case 127: // expr_lv8
      case 128: // expr_lv9
      case 129: // expr_lv10
      case 130: // expr_lv11
      case 131: // expr_lv12
      case 132: // expr_ptype
      case 133: // expr_unary
      case 134: // expr_unary_logic
      case 135: // expr_pp
      case 136: // expr_post
      case 137: // expr_prime
      case 138: // expr_prime_noname
      case 139: // expr_prime_cx
      case 140: // expr_prime_cx_nude
      case 141: // expr_call
      case 142: // expr_field
      case 143: // expr_new
      case 144: // expr_new_plain
      case 145: // callee
      case 146: // name
      case 148: // special_name
        value.move< Ast* > (s.value);
        break;

      case 93: // class_list
      case 95: // member_list
      case 97: // param_list
      case 98: // param_list_noemp
      case 100: // stmt_list
      case 103: // arg_list
      case 104: // arg_list_noemp
      case 106: // dector_list
      case 114: // try_list
      case 115: // catch_list
      case 117: // if_list
      case 147: // name_list
        value.move< ListAst* > (s.value);
        break;

      case 91: // modifiers
      case 92: // modifier
        value.move< Modifiers > (s.value);
        break;

      case 149: // dims
        value.move< int > (s.value);
        break;

      case 82: // "identifier"
      case 83: // "number"
      case 84: // "string"
      case 85: // "void"
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  BisonParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  BisonParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  BisonParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  BisonParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  BisonParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  BisonParser::by_type::type_get () const
  {
    return type;
  }

  inline
  BisonParser::token_type
  BisonParser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  BisonParser::symbol_type
  BisonParser::make_END (const location_type& l)
  {
    return symbol_type (token::TOK_END, l);
  }

  BisonParser::symbol_type
  BisonParser::make_CLASS (const location_type& l)
  {
    return symbol_type (token::TOK_CLASS, l);
  }

  BisonParser::symbol_type
  BisonParser::make_INTERFACE (const location_type& l)
  {
    return symbol_type (token::TOK_INTERFACE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_EXTENDS (const location_type& l)
  {
    return symbol_type (token::TOK_EXTENDS, l);
  }

  BisonParser::symbol_type
  BisonParser::make_IMPLEMENTS (const location_type& l)
  {
    return symbol_type (token::TOK_IMPLEMENTS, l);
  }

  BisonParser::symbol_type
  BisonParser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::TOK_WHILE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_DO (const location_type& l)
  {
    return symbol_type (token::TOK_DO, l);
  }

  BisonParser::symbol_type
  BisonParser::make_FOR (const location_type& l)
  {
    return symbol_type (token::TOK_FOR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_IF (const location_type& l)
  {
    return symbol_type (token::TOK_IF, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::TOK_ELSE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_RETURN (const location_type& l)
  {
    return symbol_type (token::TOK_RETURN, l);
  }

  BisonParser::symbol_type
  BisonParser::make_BREAK (const location_type& l)
  {
    return symbol_type (token::TOK_BREAK, l);
  }

  BisonParser::symbol_type
  BisonParser::make_CONTINUE (const location_type& l)
  {
    return symbol_type (token::TOK_CONTINUE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_THROW (const location_type& l)
  {
    return symbol_type (token::TOK_THROW, l);
  }

  BisonParser::symbol_type
  BisonParser::make_THROWS (const location_type& l)
  {
    return symbol_type (token::TOK_THROWS, l);
  }

  BisonParser::symbol_type
  BisonParser::make_INSTANCEOF (const location_type& l)
  {
    return symbol_type (token::TOK_INSTANCEOF, l);
  }

  BisonParser::symbol_type
  BisonParser::make_JNULL (const location_type& l)
  {
    return symbol_type (token::TOK_JNULL, l);
  }

  BisonParser::symbol_type
  BisonParser::make_THIS (const location_type& l)
  {
    return symbol_type (token::TOK_THIS, l);
  }

  BisonParser::symbol_type
  BisonParser::make_SUPER (const location_type& l)
  {
    return symbol_type (token::TOK_SUPER, l);
  }

  BisonParser::symbol_type
  BisonParser::make_NEW (const location_type& l)
  {
    return symbol_type (token::TOK_NEW, l);
  }

  BisonParser::symbol_type
  BisonParser::make_TRY (const location_type& l)
  {
    return symbol_type (token::TOK_TRY, l);
  }

  BisonParser::symbol_type
  BisonParser::make_CATCH (const location_type& l)
  {
    return symbol_type (token::TOK_CATCH, l);
  }

  BisonParser::symbol_type
  BisonParser::make_FINALLY (const location_type& l)
  {
    return symbol_type (token::TOK_FINALLY, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ABSTRACT (const location_type& l)
  {
    return symbol_type (token::TOK_ABSTRACT, l);
  }

  BisonParser::symbol_type
  BisonParser::make_FINAL (const location_type& l)
  {
    return symbol_type (token::TOK_FINAL, l);
  }

  BisonParser::symbol_type
  BisonParser::make_PUBLIC (const location_type& l)
  {
    return symbol_type (token::TOK_PUBLIC, l);
  }

  BisonParser::symbol_type
  BisonParser::make_PROTECTED (const location_type& l)
  {
    return symbol_type (token::TOK_PROTECTED, l);
  }

  BisonParser::symbol_type
  BisonParser::make_PRIVATE (const location_type& l)
  {
    return symbol_type (token::TOK_PRIVATE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_STATIC (const location_type& l)
  {
    return symbol_type (token::TOK_STATIC, l);
  }

  BisonParser::symbol_type
  BisonParser::make_TRANSIENT (const location_type& l)
  {
    return symbol_type (token::TOK_TRANSIENT, l);
  }

  BisonParser::symbol_type
  BisonParser::make_VOLATILE (const location_type& l)
  {
    return symbol_type (token::TOK_VOLATILE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_NATIVE (const location_type& l)
  {
    return symbol_type (token::TOK_NATIVE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_SYNCHRONIZED (const location_type& l)
  {
    return symbol_type (token::TOK_SYNCHRONIZED, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASSIGN (const location_type& l)
  {
    return symbol_type (token::TOK_ASSIGN, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_SUB (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_SUB, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_ADD (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_ADD, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_MUL (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_MUL, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_DIV (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_DIV, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_MOD (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_MOD, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_AND (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_AND, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_XOR (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_XOR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_OR (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_OR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_SHL (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_SHL, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_SHR (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_SHR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ASS_SHRA (const location_type& l)
  {
    return symbol_type (token::TOK_ASS_SHRA, l);
  }

  BisonParser::symbol_type
  BisonParser::make_SUB (const location_type& l)
  {
    return symbol_type (token::TOK_SUB, l);
  }

  BisonParser::symbol_type
  BisonParser::make_ADD (const location_type& l)
  {
    return symbol_type (token::TOK_ADD, l);
  }

  BisonParser::symbol_type
  BisonParser::make_MUL (const location_type& l)
  {
    return symbol_type (token::TOK_MUL, l);
  }

  BisonParser::symbol_type
  BisonParser::make_DIV (const location_type& l)
  {
    return symbol_type (token::TOK_DIV, l);
  }

  BisonParser::symbol_type
  BisonParser::make_MOD (const location_type& l)
  {
    return symbol_type (token::TOK_MOD, l);
  }

  BisonParser::symbol_type
  BisonParser::make_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_COLON, l);
  }

  BisonParser::symbol_type
  BisonParser::make_QUESTION (const location_type& l)
  {
    return symbol_type (token::TOK_QUESTION, l);
  }

  BisonParser::symbol_type
  BisonParser::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::TOK_SEMICOLON, l);
  }

  BisonParser::symbol_type
  BisonParser::make_DOT (const location_type& l)
  {
    return symbol_type (token::TOK_DOT, l);
  }

  BisonParser::symbol_type
  BisonParser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::TOK_COMMA, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LBRACE (const location_type& l)
  {
    return symbol_type (token::TOK_LBRACE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_RBRACE (const location_type& l)
  {
    return symbol_type (token::TOK_RBRACE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LSQUARE (const location_type& l)
  {
    return symbol_type (token::TOK_LSQUARE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_RSQUARE (const location_type& l)
  {
    return symbol_type (token::TOK_RSQUARE, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_LPAREN, l);
  }

  BisonParser::symbol_type
  BisonParser::make_RPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_RPAREN, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LOGIC_OR (const location_type& l)
  {
    return symbol_type (token::TOK_LOGIC_OR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LOGIC_AND (const location_type& l)
  {
    return symbol_type (token::TOK_LOGIC_AND, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LOGIC_NOT (const location_type& l)
  {
    return symbol_type (token::TOK_LOGIC_NOT, l);
  }

  BisonParser::symbol_type
  BisonParser::make_BIT_OR (const location_type& l)
  {
    return symbol_type (token::TOK_BIT_OR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_BIT_AND (const location_type& l)
  {
    return symbol_type (token::TOK_BIT_AND, l);
  }

  BisonParser::symbol_type
  BisonParser::make_BIT_XOR (const location_type& l)
  {
    return symbol_type (token::TOK_BIT_XOR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_BIT_NOT (const location_type& l)
  {
    return symbol_type (token::TOK_BIT_NOT, l);
  }

  BisonParser::symbol_type
  BisonParser::make_EQ (const location_type& l)
  {
    return symbol_type (token::TOK_EQ, l);
  }

  BisonParser::symbol_type
  BisonParser::make_NEQ (const location_type& l)
  {
    return symbol_type (token::TOK_NEQ, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LT (const location_type& l)
  {
    return symbol_type (token::TOK_LT, l);
  }

  BisonParser::symbol_type
  BisonParser::make_GT (const location_type& l)
  {
    return symbol_type (token::TOK_GT, l);
  }

  BisonParser::symbol_type
  BisonParser::make_LEQ (const location_type& l)
  {
    return symbol_type (token::TOK_LEQ, l);
  }

  BisonParser::symbol_type
  BisonParser::make_GEQ (const location_type& l)
  {
    return symbol_type (token::TOK_GEQ, l);
  }

  BisonParser::symbol_type
  BisonParser::make_SHL (const location_type& l)
  {
    return symbol_type (token::TOK_SHL, l);
  }

  BisonParser::symbol_type
  BisonParser::make_SHR (const location_type& l)
  {
    return symbol_type (token::TOK_SHR, l);
  }

  BisonParser::symbol_type
  BisonParser::make_SHRA (const location_type& l)
  {
    return symbol_type (token::TOK_SHRA, l);
  }

  BisonParser::symbol_type
  BisonParser::make_INC (const location_type& l)
  {
    return symbol_type (token::TOK_INC, l);
  }

  BisonParser::symbol_type
  BisonParser::make_DEC (const location_type& l)
  {
    return symbol_type (token::TOK_DEC, l);
  }

  BisonParser::symbol_type
  BisonParser::make_DIM (const location_type& l)
  {
    return symbol_type (token::TOK_DIM, l);
  }

  BisonParser::symbol_type
  BisonParser::make_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_IDENTIFIER, v, l);
  }

  BisonParser::symbol_type
  BisonParser::make_NUMBER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_NUMBER, v, l);
  }

  BisonParser::symbol_type
  BisonParser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING, v, l);
  }

  BisonParser::symbol_type
  BisonParser::make_VOID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_VOID, v, l);
  }



} // yy
#line 2242 "bison.hh" // lalr1.cc:377




#endif // !YY_YY_BISON_HH_INCLUDED
