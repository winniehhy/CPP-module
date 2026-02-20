#!/bin/bash

# Colors
GRN="$(printf '\033[1;32m')"
RED="$(printf '\033[1;31m')"
YEL="$(printf '\033[1;33m')"
BLU="$(printf '\033[1;34m')"
RST="$(printf '\033[0m')"

PASS=0
FAIL=0

# ─── Test cases ───────────────────────────────────────────────
inputs=(
  # Normal cases
  "8 1 +"
  "9 5 -"
  "7 6 *"
  "9 3 /"
  "2 3 + 4 +"
  "8 2 / 3 *"
  "5 9 1 - *"
  "9 2 3 + /"
  "4 2 / 2 /"
  "3 3 * 2 - 4 /"
  "6 2 3 * +"
  "5 9 + 8 7 - *"
  "8 5 2 * -"
  "9 1 - 8 2 / +"
  "7 3 - 2 2 + *"
  "6 2 / 2 / 2 /"
  "0 7 7 - +"

  # Subject examples
  "8 9 * 9 - 9 - 9 - 4 - 1 +"
  "7 7 * 7 -"
  "1 2 * 2 / 2 * 2 4 - +"

  # Negative result
  "8 5 2 * -"

  # Error cases
  "8 0 /"
  "9 0 0 / +"
  "4 a +"
  "1 +"
  "2 2 2 +"
  "12 3 +"
  "(1 + 1)"
  "+"
)

expected=(
  # Normal cases
  "9"
  "4"
  "42"
  "3"
  "9"
  "12"
  "40"
  "1"
  "1"
  "1"
  "12"
  "14"
  "-2"
  "12"
  "16"
  "0"
  "0"

  # Subject examples
  "42"
  "42"
  "0"

  # Negative result
  "-2"

  # Error cases
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
)

# ─── Build ────────────────────────────────────────────────────
if [ -f Makefile ]; then
  echo "${YEL}Building...${RST}"
  if ! make -s; then
    echo "${RED}Build failed.${RST}"
    exit 2
  fi
  echo ""
fi

if [ ! -x ./RPN ]; then
  echo "${RED}./RPN not found or not executable.${RST}"
  exit 2
fi

# ─── Run tests ────────────────────────────────────────────────
echo "═══════════════════════════════════════════════════"
echo "               RPN TEST RUNNER"
echo "═══════════════════════════════════════════════════"

for i in "${!inputs[@]}"; do
  expr="${inputs[$i]}"
  exp="${expected[$i]}"

  tmp_err=".$$.rpn.err"
  out="$(./RPN "$expr" 2>"$tmp_err")"
  status=$?
  err="$(cat "$tmp_err")"
  rm -f "$tmp_err"

  # Determine actual result
  if [ "$exp" = "Error" ]; then
    if [ $status -ne 0 ] || [ -n "$err" ]; then
      actual="Error"
    else
      actual="$out"
    fi
  else
    actual="$out"
  fi

  # Compare
  if [ "$actual" = "$exp" ]; then
    result="${GRN}PASS${RST}"
    ((PASS++))
  else
    result="${RED}FAIL${RST}"
    ((FAIL++))
  fi

  printf "%-40s  exp: %-6s  got: %-6s  [%s]\n" \
    "\"$expr\"" "$exp" "$actual" "$result"
done

# ─── Summary ──────────────────────────────────────────────────
echo "═══════════════════════════════════════════════════"
echo "  Results: ${GRN}$PASS passed${RST}  |  ${RED}$FAIL failed${RST}  |  total $((PASS + FAIL))"
echo "═══════════════════════════════════════════════════"

[ $FAIL -eq 0 ] && exit 0 || exit 1