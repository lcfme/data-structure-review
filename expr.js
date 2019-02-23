function is_number(ch) {
  return ch && /\d/.test(ch) && ch;
}

function is_op(ch) {
  return ch && /\+|\-|\*|\//.test(ch) && ch;
}

function is_whitespace(ch) {
  return ch && /\s/.test(ch) && ch;
}

function is_identifier(ch) {
  return ch && /[A-z_$]/.test(ch) && ch;
}

class Token {
  constructor(Type, Val) {
    this.Type = Type;
    this.Val = Val;
  }
}

class Lexer {
  constructor(input = '') {
    this.input = input;
    this.at = 0;
  }
  readChar() {
    const ch = this.input.charAt(this.at);
    if (this.at < this.input.length) {
      this.at++;
    }
    return ch;
  }
  peekChar() {
    return this.input.charAt(this.at);
  }
  nextToken() {
    while (is_whitespace(this.peekChar())) this.readChar();
    const ch = this.peekChar();
    if (!ch) {
      return null;
    }
    let tok;
    if (ch == '(') {
      tok = new Token('LPAREN', ch);
      this.readChar();
    } else if (ch == ')') {
      tok = new Token('RPAREN', ch);
      this.readChar();
    } else if (is_identifier(ch)) {
      tok = this.parseIdentifier();
    } else if (is_number(ch)) {
      tok = this.parseNumber();
    } else if (is_op(ch)) {
      tok = this.parseOp();
    } else {
      throw new Error(`Invalid char at:${this.at}`);
    }
    return tok;
  }
  parseNumber() {
    let val = '';
    while (is_number(this.peekChar())) {
      val += this.readChar();
    }
    return new Token('Number', parseInt(val, 10));
  }
  parseIdentifier() {
    let val = '';
    while (
      !val.length
        ? is_identifier(this.peekChar())
        : is_identifier(this.peekChar()) || is_number(this.peekChar())
    ) {
      val += this.readChar();
    }
    return new Token('Identifier', val);
  }
  parseOp() {
    let val = '';
    while (is_op(this.peekChar())) {
      val += this.readChar();
    }
    return new Token('Op', val);
  }
}

class RootExpr {
  constructor(expr) {
    this.expr = expr;
  }
}

class UnaryExpr {
  constructor(Op, Left) {
    this.Op = Op;
    this.Left = Left;
  }
}

class BinaryExpr {
  constructor(Op, Left, Right) {
    this.Op = Op;
    this.Left = Left;
    this.Right = Right;
  }
}

class InFix {
  constructor(l) {
    this.curToken = null;
  }
  resolvePrecedence(op) {
    var PRECEDENCE = {
      '+': 13,
      '-': 13,
      '*': 14,
      '/': 14,
      '%': 14
    };
    let prec = PRECEDENCE[op];
    return prec || 0;
  }
  next() {
    this.curToken = l.nextToken();
    return this.curToken;
  }
  peek() {
    return this.curToken ? this.curToken : (this.curToken = l.nextToken());
  }
  parse() {
    let expr;
    const tok = this.peek();
    if (!tok) return null;
    expr = new RootExpr(this.parseExpr(0));
    if (this.peek()) {
      throw new Error(`Remained token. ${JSON.stringify(this.peek())}`);
    }
    return expr;
  }
  parseExpr(prec = 0) {
    // prefixExpr
    const tok = this.peek();
    let expr;
    if (tok.Type === 'LPAREN') {
      this.next();
      expr = this.parseExpr(0);
      if (this.peek().Type !== 'RPAREN') {
        throw new Error(`Invalid token. ${JSON.stringify(this.peek())}`);
      }
      this.next();
    } else if (tok.Type === 'Number' || tok.Type === 'Identifier') {
      expr = tok;
      this.next();
    } else if (tok.Type === 'Op' && (tok.Val === '+' || tok.Val === '-')) {
      expr = this.parseUnaryExpr();
    }
    // infixExpr
    while (this.peek() && this.resolvePrecedence(this.peek().Val) > prec) {
      expr = this.parseInfixExpr(expr);
    }
    return expr;
  }
  parseUnaryExpr() {
    const op = this.peek();
    this.next();
    return new UnaryExpr(op, this.parseExpr(0));
  }
  parseInfixExpr(left) {
    const op = this.peek();
    this.next();
    return new BinaryExpr(
      op,
      left,
      this.parseExpr(this.resolvePrecedence(op.Val))
    );
  }
}

var l = new Lexer('a * (b+c) - d');
var p = new InFix(l);
p.parse();
