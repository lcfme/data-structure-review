const ast = {
  type: 'FunctionDeclaration',
  id: {
    type: 'Identifier',
    name: 'square'
  },
  params: [
    {
      type: 'Identifier',
      name: 'n'
    }
  ],
  body: {
    type: 'BlockStatement',
    body: [
      {
        type: 'ReturnStatement',
        argument: {
          type: 'BinaryExpression',
          operator: '*',
          left: {
            type: 'Identifier',
            name: 'n'
          },
          right: {
            type: 'Identifier',
            name: 'n'
          }
        }
      }
    ]
  }
};

function astTraverse(ast, opts) {
  opts = opts || {};
  if (Array.isArray(ast)) {
    for (let i = 0, len = ast.length; i < len; ++i) {
      astTraverse(ast[i], opts);
    }
    return;
  }
  const type = isTypeofNode(ast);
  if (!type) return;
  if (opts[type].entry) {
    opts[type].entry.call(ast);
  }
  for (let prop in ast) {
    astTraverse(ast[prop], opts);
  }
  if (opts[type].leave) {
    opts[type].leave.call(ast);
  }
}

function isTypeofNode(obj) {
  return obj && obj.type;
}

astTraverse(ast, {
  FunctionDeclaration: {
    entry() {
      console.log('entry', this);
    },
    leave() {
      console.log('leave', this);
    }
  },
  Identifier: {
    entry() {
      console.log('entry', this);
    },
    leave() {
      if (this.name === 'square') {
        this.name = 'fuck';
      }
      console.log('leave', this);
    }
  },
  BlockStatement: {
    entry() {
      console.log('entry', this);
    },
    leave() {
      console.log('leave', this);
    }
  },
  ReturnStatement: {
    entry() {
      console.log('entry', this);
    },
    leave() {
      console.log('leave', this);
    }
  },
  BinaryExpression: {
    entry() {
      console.log('entry', this);
    },
    leave() {
      console.log('leave', this);
    }
  }
});
