// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "astparser-0.hpp"




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


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



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
      *yycdebug_ << '\n';                       \
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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 117 "astparser-0.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // startsymb: lfmprog
#line 60 "astparser-0.yy"
                        { }
#line 538 "astparser-0.cpp"
    break;

  case 3: // lfmprog: deflist main
#line 63 "astparser-0.yy"
                        { }
#line 544 "astparser-0.cpp"
    break;

  case 4: // deflist: def deflist
#line 66 "astparser-0.yy"
                        { }
#line 550 "astparser-0.cpp"
    break;

  case 5: // deflist: %empty
#line 67 "astparser-0.yy"
                        { }
#line 556 "astparser-0.cpp"
    break;

  case 6: // def: extdef
#line 70 "astparser-0.yy"
                        { }
#line 562 "astparser-0.cpp"
    break;

  case 7: // def: funcdef
#line 71 "astparser-0.yy"
                        { }
#line 568 "astparser-0.cpp"
    break;

  case 8: // extdef: "external" prototype
#line 74 "astparser-0.yy"
                        { }
#line 574 "astparser-0.cpp"
    break;

  case 9: // funcdef: "function" prototype expr "end"
#line 77 "astparser-0.yy"
                                   { }
#line 580 "astparser-0.cpp"
    break;

  case 10: // prototype: "id" "(" params ")"
#line 80 "astparser-0.yy"
                        { }
#line 586 "astparser-0.cpp"
    break;

  case 11: // params: %empty
#line 83 "astparser-0.yy"
                        { }
#line 592 "astparser-0.cpp"
    break;

  case 12: // params: "id" params
#line 84 "astparser-0.yy"
                        { }
#line 598 "astparser-0.cpp"
    break;

  case 13: // main: expr
#line 87 "astparser-0.yy"
                        { }
#line 604 "astparser-0.cpp"
    break;

  case 14: // main: %empty
#line 88 "astparser-0.yy"
                        { }
#line 610 "astparser-0.cpp"
    break;

  case 15: // expr: expr "+" expr
#line 99 "astparser-0.yy"
                         { }
#line 616 "astparser-0.cpp"
    break;

  case 16: // expr: expr "-" expr
#line 100 "astparser-0.yy"
                         { }
#line 622 "astparser-0.cpp"
    break;

  case 17: // expr: expr "*" expr
#line 101 "astparser-0.yy"
                         { }
#line 628 "astparser-0.cpp"
    break;

  case 18: // expr: expr "/" expr
#line 102 "astparser-0.yy"
                         { }
#line 634 "astparser-0.cpp"
    break;

  case 19: // expr: expr "%" expr
#line 103 "astparser-0.yy"
                         { }
#line 640 "astparser-0.cpp"
    break;

  case 20: // expr: "-" expr
#line 104 "astparser-0.yy"
                         { }
#line 646 "astparser-0.cpp"
    break;

  case 21: // expr: "(" expr ")"
#line 105 "astparser-0.yy"
                         { }
#line 652 "astparser-0.cpp"
    break;

  case 22: // expr: "id"
#line 106 "astparser-0.yy"
                         { }
#line 658 "astparser-0.cpp"
    break;

  case 23: // expr: "id" "(" arglist ")"
#line 107 "astparser-0.yy"
                         { }
#line 664 "astparser-0.cpp"
    break;

  case 24: // expr: "number"
#line 108 "astparser-0.yy"
                         { }
#line 670 "astparser-0.cpp"
    break;

  case 25: // expr: condexpr
#line 109 "astparser-0.yy"
                         { }
#line 676 "astparser-0.cpp"
    break;

  case 26: // expr: letexpr
#line 110 "astparser-0.yy"
                         { }
#line 682 "astparser-0.cpp"
    break;

  case 27: // arglist: %empty
#line 113 "astparser-0.yy"
                         { }
#line 688 "astparser-0.cpp"
    break;

  case 28: // arglist: args
#line 114 "astparser-0.yy"
                         { }
#line 694 "astparser-0.cpp"
    break;

  case 29: // args: expr
#line 117 "astparser-0.yy"
                         { }
#line 700 "astparser-0.cpp"
    break;

  case 30: // args: expr "," args
#line 118 "astparser-0.yy"
                         { }
#line 706 "astparser-0.cpp"
    break;

  case 31: // condexpr: "if" pairs "end"
#line 121 "astparser-0.yy"
                         { }
#line 712 "astparser-0.cpp"
    break;

  case 32: // pairs: pair
#line 124 "astparser-0.yy"
                         { }
#line 718 "astparser-0.cpp"
    break;

  case 33: // pairs: pair ";" pairs
#line 125 "astparser-0.yy"
                           { }
#line 724 "astparser-0.cpp"
    break;

  case 34: // pair: boolexpr ":" expr
#line 128 "astparser-0.yy"
                         { }
#line 730 "astparser-0.cpp"
    break;

  case 35: // boolexpr: boolexpr "and" boolexpr
#line 131 "astparser-0.yy"
                          { }
#line 736 "astparser-0.cpp"
    break;

  case 36: // boolexpr: boolexpr "or" boolexpr
#line 132 "astparser-0.yy"
                          { }
#line 742 "astparser-0.cpp"
    break;

  case 37: // boolexpr: "not" boolexpr
#line 133 "astparser-0.yy"
                               { }
#line 748 "astparser-0.cpp"
    break;

  case 38: // boolexpr: literal
#line 134 "astparser-0.yy"
                          { }
#line 754 "astparser-0.cpp"
    break;

  case 39: // boolexpr: relexpr
#line 135 "astparser-0.yy"
                          { }
#line 760 "astparser-0.cpp"
    break;

  case 40: // literal: "true"
#line 138 "astparser-0.yy"
                          { }
#line 766 "astparser-0.cpp"
    break;

  case 41: // literal: "false"
#line 139 "astparser-0.yy"
                          { }
#line 772 "astparser-0.cpp"
    break;

  case 42: // relexpr: expr "<" expr
#line 142 "astparser-0.yy"
                          { }
#line 778 "astparser-0.cpp"
    break;

  case 43: // relexpr: expr "==" expr
#line 143 "astparser-0.yy"
                          { }
#line 784 "astparser-0.cpp"
    break;

  case 44: // relexpr: expr "<>" expr
#line 144 "astparser-0.yy"
                          { }
#line 790 "astparser-0.cpp"
    break;

  case 45: // relexpr: expr "<=" expr
#line 145 "astparser-0.yy"
                          { }
#line 796 "astparser-0.cpp"
    break;

  case 46: // relexpr: expr ">" expr
#line 146 "astparser-0.yy"
                          { }
#line 802 "astparser-0.cpp"
    break;

  case 47: // relexpr: expr ">=" expr
#line 147 "astparser-0.yy"
                          { }
#line 808 "astparser-0.cpp"
    break;

  case 48: // letexpr: "let" bindings "in" expr "end"
#line 150 "astparser-0.yy"
                                 {}
#line 814 "astparser-0.cpp"
    break;

  case 49: // bindings: binding
#line 153 "astparser-0.yy"
                          { }
#line 820 "astparser-0.cpp"
    break;

  case 50: // bindings: binding "," bindings
#line 154 "astparser-0.yy"
                          { }
#line 826 "astparser-0.cpp"
    break;

  case 51: // binding: "id" "=" expr
#line 157 "astparser-0.yy"
                          { }
#line 832 "astparser-0.cpp"
    break;


#line 836 "astparser-0.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
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

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -30;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -19,   -17,   -17,    19,   -30,    49,   -19,   -30,   -30,     9,
     -30,    49,   -30,    49,    49,    -4,   -10,    12,   -30,   -30,
      95,   -30,   -30,   -30,    -2,    35,   -30,     4,   -30,   -30,
      -4,    81,     2,    30,     0,   -30,   -30,    32,    23,    51,
      49,    49,    49,    49,    49,    49,    -2,    47,   -30,   -30,
     -30,    49,    49,    49,    49,    49,    49,   -30,    -4,    49,
      -4,    -4,    49,    49,   -10,    62,    61,   -30,    67,    67,
     -30,   -30,   -30,   -30,   -30,    95,    95,    95,    95,    95,
      95,   -30,    95,   -30,    53,    95,    55,   -30,    49,   -30,
     -30,   -30
  };

  const signed char
  parser::yydefact_[] =
  {
       5,     0,     0,     0,     2,    14,     5,     6,     7,     0,
       8,     0,     1,     0,     0,     0,     0,    22,    24,     3,
      13,    25,    26,     4,    11,     0,    20,     0,    40,    41,
       0,     0,     0,    32,     0,    38,    39,     0,     0,    49,
      27,     0,     0,     0,     0,     0,    11,     0,     9,    21,
      37,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,    29,     0,    28,    16,    15,
      17,    18,    19,    12,    10,    45,    42,    43,    44,    47,
      46,    33,    34,    35,    36,    51,     0,    50,     0,    23,
      48,    30
  };

  const signed char
  parser::yypgoto_[] =
  {
     -30,   -30,   -30,    74,   -30,   -30,   -30,    82,    39,   -30,
      -5,   -30,     5,   -30,    34,   -30,   -29,   -30,   -30,   -30,
      42,   -30
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    10,    47,    19,
      31,    66,    67,    21,    32,    33,    34,    35,    36,    22,
      38,    39
  };

  const signed char
  parser::yytable_[] =
  {
      20,    50,    13,    59,     1,     2,    25,    14,    26,    27,
      41,    42,    43,    44,    45,     9,    49,    28,    29,    12,
      24,    15,    37,    40,    30,    16,    60,    61,    17,    18,
      46,    83,    84,    57,    58,    65,    68,    69,    70,    71,
      72,    41,    42,    43,    44,    45,    75,    76,    77,    78,
      79,    80,    62,    63,    82,    13,    64,    85,    86,    74,
      14,    41,    42,    43,    44,    45,    48,    88,    41,    42,
      43,    44,    45,    89,    15,    43,    44,    45,    16,    60,
      23,    17,    18,    65,    11,    73,    90,    41,    42,    43,
      44,    45,    81,    91,     0,    51,    52,    53,    54,    55,
      56,    41,    42,    43,    44,    45,    87
  };

  const signed char
  parser::yycheck_[] =
  {
       5,    30,     6,     3,    23,    24,    11,    11,    13,    14,
       6,     7,     8,     9,    10,    32,    12,    21,    22,     0,
      11,    25,    32,    11,    28,    29,    26,    27,    32,    33,
      32,    60,    61,    31,     4,    40,    41,    42,    43,    44,
      45,     6,     7,     8,     9,    10,    51,    52,    53,    54,
      55,    56,    20,    30,    59,     6,     5,    62,    63,    12,
      11,     6,     7,     8,     9,    10,    31,     5,     6,     7,
       8,     9,    10,    12,    25,     8,     9,    10,    29,    26,
       6,    32,    33,    88,     2,    46,    31,     6,     7,     8,
       9,    10,    58,    88,    -1,    14,    15,    16,    17,    18,
      19,     6,     7,     8,     9,    10,    64
  };

  const signed char
  parser::yystos_[] =
  {
       0,    23,    24,    37,    38,    39,    40,    41,    42,    32,
      43,    43,     0,     6,    11,    25,    29,    32,    33,    45,
      46,    49,    55,    39,    11,    46,    46,    46,    21,    22,
      28,    46,    50,    51,    52,    53,    54,    32,    56,    57,
      11,     6,     7,     8,     9,    10,    32,    44,    31,    12,
      52,    14,    15,    16,    17,    18,    19,    31,     4,     3,
      26,    27,    20,    30,     5,    46,    47,    48,    46,    46,
      46,    46,    46,    44,    12,    46,    46,    46,    46,    46,
      46,    50,    46,    52,    52,    46,    46,    56,     5,    12,
      31,    48
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    36,    37,    38,    39,    39,    40,    40,    41,    42,
      43,    44,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    49,    50,    50,    51,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    55,    56,
      56,    57
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     0,     1,     1,     2,     4,
       4,     0,     2,     1,     0,     3,     3,     3,     3,     3,
       2,     3,     1,     4,     1,     1,     1,     0,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     5,     1,
       3,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\":\"", "\";\"",
  "\",\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"", "\"(\"", "\")\"",
  "\"|\"", "\"<=\"", "\"<\"", "\"==\"", "\"<>\"", "\">=\"", "\">\"",
  "\"=\"", "\"true\"", "\"false\"", "\"external\"", "\"function\"",
  "\"if\"", "\"and\"", "\"or\"", "\"not\"", "\"let\"", "\"in\"", "\"end\"",
  "\"id\"", "\"number\"", "UMINUS", "NEGATE", "$accept", "startsymb",
  "lfmprog", "deflist", "def", "extdef", "funcdef", "prototype", "params",
  "main", "expr", "arglist", "args", "condexpr", "pairs", "pair",
  "boolexpr", "literal", "relexpr", "letexpr", "bindings", "binding", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    60,    60,    63,    66,    67,    70,    71,    74,    77,
      80,    83,    84,    87,    88,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   113,   114,   117,
     118,   121,   124,   125,   128,   131,   132,   133,   134,   135,
     138,   139,   142,   143,   144,   145,   146,   147,   150,   153,
     154,   157
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1364 "astparser-0.cpp"

#line 159 "astparser-0.yy"



