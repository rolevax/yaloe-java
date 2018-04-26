######################################################################
# Generated by libzuse/gen_pri.sh, do NOT modify
######################################################################


# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += libzuse/zuse.h \
           libzuse/ast/ast.h \
           libzuse/ast/ast_fix_size.h \
           libzuse/ast/ast_internal.h \
           libzuse/ast/ast_list.h \
           libzuse/ast/ast_list_bop.h \
           libzuse/ast/ast_root.h \
           libzuse/ast/ast_scalar.h \
           libzuse/ast/bison.hh \
           libzuse/ast/bop.h \
           libzuse/ast/lexproto.h \
           libzuse/ast/location.hh \
           libzuse/ast/modifiers.h \
           libzuse/ast/parse_exception.h \
           libzuse/ast/parser.h \
           libzuse/ast/position.hh \
           libzuse/ast/stack.hh \
           libzuse/core/doc.h \
           libzuse/core/doc_editable.h \
           libzuse/core/doc_listener.h \
           libzuse/core/hammer.h \
           libzuse/core/keycode.h \
           libzuse/core/token.h \
           libzuse/core/token_bone.h \
           libzuse/core/token_flesh.h \
           libzuse/core/token_soul.h \
           libzuse/core/tokens.h \
           libzuse/mode/macro_handler.h \
           libzuse/mode/mode.h \
           libzuse/mode/mode_input_fix_size.h \
           libzuse/mode/mode_input_ident.h \
           libzuse/mode/mode_input_list.h \
           libzuse/mode/mode_input_number.h \
           libzuse/mode/mode_input_string.h \
           libzuse/mode/mode_menu.h \
           libzuse/mode/mode_moggle.h \
           libzuse/mode/mode_normal.h \
           libzuse/mode/mode_tilex.h \
           libzuse/util/pointers.h
SOURCES += libzuse/ast/ast.cpp \
           libzuse/ast/ast_fix_size.cpp \
           libzuse/ast/ast_internal.cpp \
           libzuse/ast/ast_list.cpp \
           libzuse/ast/ast_list_bop.cpp \
           libzuse/ast/ast_root.cpp \
           libzuse/ast/ast_scalar.cpp \
           libzuse/ast/bison.cc \
           libzuse/ast/lex.cpp \
           libzuse/ast/parser.cpp \
           libzuse/core/doc.cpp \
           libzuse/core/hammer.cpp \
           libzuse/core/keycode.cpp \
           libzuse/core/token.cpp \
           libzuse/core/token_bone.cpp \
           libzuse/core/token_flesh.cpp \
           libzuse/core/token_soul.cpp \
           libzuse/core/tokens.cpp \
           libzuse/mode/macro_handler.cpp \
           libzuse/mode/mode_input_fix_size.cpp \
           libzuse/mode/mode_input_ident.cpp \
           libzuse/mode/mode_input_list.cpp \
           libzuse/mode/mode_input_number.cpp \
           libzuse/mode/mode_input_string.cpp \
           libzuse/mode/mode_menu.cpp \
           libzuse/mode/mode_moggle.cpp \
           libzuse/mode/mode_normal.cpp \
           libzuse/mode/mode_tilex.cpp
