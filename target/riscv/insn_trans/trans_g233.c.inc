

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