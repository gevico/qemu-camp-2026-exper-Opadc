

static bool trans_dma(DisasContext *ctx, arg_dma *a){
    TCGv src = get_gpr(ctx, a->rs1, EXT_NONE);
    TCGv type = get_gpr(ctx, a->rs2, EXT_NONE);
    TCGv dest = get_gpr(ctx, a->rd, EXT_NONE);

    gen_helper_dma(tcg_env, src, type, dest);
    return true;
}

static bool trans_sort(DisasContext *ctx, arg_dma *a){
    TCGv src = get_gpr(ctx, a->rs1, EXT_NONE);
    TCGv size = get_gpr(ctx, a->rs2, EXT_NONE);
    TCGv nums = get_gpr(ctx, a->rd, EXT_NONE);

    gen_helper_sort(tcg_env, src, size, nums);
    return true;
}

static bool trans_crush(DisasContext *ctx, arg_dma *a){
    TCGv src = get_gpr(ctx, a->rs1, EXT_NONE);
    TCGv size = get_gpr(ctx, a->rs2, EXT_NONE);
    TCGv dest = get_gpr(ctx, a->rd, EXT_NONE);

    gen_helper_crush(tcg_env, src, size, dest);
    return true;
}


static bool trans_expand(DisasContext *ctx, arg_dma *a){
    TCGv src = get_gpr(ctx, a->rs1, EXT_NONE);
    TCGv size = get_gpr(ctx, a->rs2, EXT_NONE);
    TCGv dest = get_gpr(ctx, a->rd, EXT_NONE);

    gen_helper_expand(tcg_env, src, size, dest);
    return true;
}

static bool trans_vdot(DisasContext *ctx, arg_dma *a){
    TCGv A = get_gpr(ctx, a->rs1, EXT_NONE);
    TCGv B = get_gpr(ctx, a->rs2, EXT_NONE);
    TCGv res = tcg_constant_tl(a->rd);

    gen_helper_vdot(tcg_env, A, B, res);
    return true;
}