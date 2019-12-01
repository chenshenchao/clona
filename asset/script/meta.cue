# 因素原型
archetype Factor {
    # 初始化
    new(now, max = nil, min=0) {
        this.now = now;
        this.max = max ?? now;
        this.min = min;
    }
}

# 位置原型
archetype Position {
    new(x = 0, y = 0) {
        this.x = x;
        this.y = y;
    }
}