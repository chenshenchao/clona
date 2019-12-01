# 属性原型
archetype Quality {
	# 初始化
	new() {
		this.hp = new Factor(100);
		this.mp = new Factor(100);
	}
}

# 角色原型
archetype Role {
	autoid = 0;

	# 初始化
	new() {
		this.id = ++autoid;
		this.position = new Position(0,0);
		this.raw = new Quality();
		this.now = new Quality();
	}
}