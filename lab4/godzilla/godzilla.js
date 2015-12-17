var D = 300;
var CITY_COLOR = "#795548";
var ROAD_COLOR = "#BDBDBD";
var GODZILLA_COLOR = "#4CAF50";
var STEP_COLOR = "#81C784";
var BORDER_COLOR = "#FF9800";

var CELL_TYPE = {
    C : 0,
    R : 1,
    G : 2,
};

function Environment (cells) {
    this.DIM = cells[0].length;
    this._cells = cells;

    var that = this;

    this.get = function (i, j) {
        return that._cells[i][j];
    };

    this.mark_godzilla = function (i, j) {
        that._cells[i][j] = CELL_TYPE.G;
    };
}

function Map (env) {
    this.env = env;
    this._table = undefined;

    var that = this;

    this._get_table = function () {
        if (that._table === undefined) {
            that._table = $("#map");
        }
        return that._table
    };

    this.get = function (i, j) {
        var cell = that._get_table()[0].rows[i + 1].cells[j + 1];
        return $(cell);
    };

    this._color_cell = function (i, j, col) {
        var cell = that.get(i, j);
        cell.css("background-color", col);
    };

    // 0 -> up
    // 1 -> right
    // 2 -> down
    // 3 -> left
    this.highlight_direction = function (i, j, dir) {
        var cell = that.get(i, j);
        var prop = "";
        switch (dir) {
            case 0:
                prop = "border-top-color";
                break;
            case 1:
                prop = "border-right-color";
                break;
            case 2:
                prop = "border-bottom-color";
                break;
            default:
                prop = "border-left-color";
        }
        cell.css(prop, BORDER_COLOR);
    };


    this.destroy = function (i, j) {
        that._color_cell(i, j, GODZILLA_COLOR);
    };

    this.step = function (i, j) {
        that._color_cell(i, j, STEP_COLOR);
    };

    this.draw = function () {
        var dim = that.env.DIM;
        for (var i = 0; i < dim; i++) {
            for (var j = 0; j < dim; j++) {
                switch (that.env.get(i, j)) {
                    case CELL_TYPE.R:
                        that._color_cell(i, j, ROAD_COLOR);
                        break;
                    default:
                        that._color_cell(i, j, CITY_COLOR);
                }
            }
        }
    };
}


function Godzilla (i, j, map) {
    this._map = map;
    this._call_stack = new Array();

    var that = this;

    this._make_dir_func = function (i, j, dir) {
        return function() {
            m.highlight_direction(i, j, dir);
        }
    };

    this._make_step_func = function (i, j) {
        return function() {
            m.step(i, j);
        }
    };

    this._make_unstep_func = function (i, j) {
        return function() {
            m.destroy(i, j);
        }
    };

    this._godzilla = function (i, j) {
        var m = that._map;
        var stack = that._call_stack;

        var left = j - 1;
        var right = j + 1;
        var up = i - 1;
        var down = i + 1;

        if (m.env.get(i, j) != CELL_TYPE.C) return;


        m.env.mark_godzilla(i, j);

        stack.push(that._make_step_func(i, j));
        stack.push(that._make_dir_func(i, j, 0));
        if (up >= 0 && m.env.get(up, j) == CELL_TYPE.C) {
            stack.push(that._make_unstep_func(i, j));
            that._godzilla(up, j);
        }

        stack.push(that._make_step_func(i, j));
        stack.push(that._make_dir_func(i, j, 1));
        if (right < m.env.DIM && m.env.get(i, right) == CELL_TYPE.C) {
            stack.push(that._make_unstep_func(i, j));
            that._godzilla(i, right);
        }

        stack.push(that._make_step_func(i, j));
        stack.push(that._make_dir_func(i, j, 2));
        if (down < m.env.DIM && m.env.get(down, j) == CELL_TYPE.C) {
            stack.push(that._make_unstep_func(i, j));
            that._godzilla(down, j);
        }

        stack.push(that._make_step_func(i, j));
        stack.push(that._make_dir_func(i, j, 3));
        if (left >= 0 && m.env.get(i, left) == CELL_TYPE.C) {
            stack.push(that._make_unstep_func(i, j));
            that._godzilla(i, left);
        }

        stack.push(that._make_unstep_func(i, j));
    }

    this.run = function () {
        that._godzilla(i, j);

        setInterval(
            function () {
                var f = that._call_stack.shift();
                if (f !== undefined) f();
            }, D);
    }
}
