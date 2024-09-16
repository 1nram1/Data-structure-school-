module stopwatch(
    input clk,              // 50MHz 主时钟输入
    input reset_start,      // 清零和启动计数开关
    input pause_resume,     // 暂停和恢复计数开关
    output reg [7:0] seg0_7,// 段选信号（seg0 - seg7）
    output reg [3:0] dig0_3 // 位选信号（dig0 - dig3）
);

    reg [25:0] cnt_1s;      // 用于生成1秒脉冲的计数器
    reg [5:0] seconds;      // 秒计数器（0-59）
    reg [5:0] minutes;      // 分钟计数器（0-59）
    reg running;            // 计时状态：运行或暂停

    // 生成1Hz的秒脉冲
    always @(posedge clk or posedge reset_start) begin
        if (reset_start)
            cnt_1s <= 0;
        else if (running) begin
            if (cnt_1s == 26'd49_999_999)
                cnt_1s <= 0;
            else
                cnt_1s <= cnt_1s + 1;
        end
    end

    wire one_sec_pulse = (cnt_1s == 26'd49_999_999);

    // 控制计时器的运行和暂停
    always @(posedge clk or posedge reset_start) begin
        if (reset_start)
            running <= 1'b1; // 启动计时
        else if (pause_resume)
            running <= ~running; // 切换运行状态
    end

    // 秒计数器
    always @(posedge clk or posedge reset_start) begin
        if (reset_start)
            seconds <= 0;
        else if (one_sec_pulse && running) begin
            if (seconds == 6'd59)
                seconds <= 0;
            else
                seconds <= seconds + 1;
        end
    end

    // 分钟计数器
    always @(posedge clk or posedge reset_start) begin
        if (reset_start)
            minutes <= 0;
        else if (one_sec_pulse && running && seconds == 6'd59) begin
            if (minutes == 6'd59)
                minutes <= 0;
            else
                minutes <= minutes + 1;
        end
    end

    // 7段数码管译码器（共阳极，段选信号为低电平有效）
    function [7:0] seg_decoder(input [3:0] digit);
        begin
            case (digit)
                4'd0: seg_decoder = 8'b1100_0000; // 显示数字0
                4'd1: seg_decoder = 8'b1111_1001; // 显示数字1
                4'd2: seg_decoder = 8'b1010_0100; // 显示数字2
                4'd3: seg_decoder = 8'b1011_0000; // 显示数字3
                4'd4: seg_decoder = 8'b1001_1001; // 显示数字4
                4'd5: seg_decoder = 8'b1001_0010; // 显示数字5
                4'd6: seg_decoder = 8'b1000_0010; // 显示数字6
                4'd7: seg_decoder = 8'b1111_1000; // 显示数字7
                4'd8: seg_decoder = 8'b1000_0000; // 显示数字8
                4'd9: seg_decoder = 8'b1001_0000; // 显示数字9
                default: seg_decoder = 8'b1111_1111; // 不显示任何数字
            endcase
        end
    endfunction

    // 显示扫描计数器，用于控制位选信号的轮流切换
    reg [13:0] scan_cnt;    // 扫描频率计数器
    reg [1:0] scan_sel;     // 当前扫描的位

    // 扫描频率设置，约为4kHz（每位约1kHz刷新率）
    always @(posedge clk) begin
        if (scan_cnt == 14'd12_499) begin // 50MHz / 12,500 = 4kHz
            scan_cnt <= 0;
            scan_sel <= scan_sel + 1;
        end else
            scan_cnt <= scan_cnt + 1;
    end

    // 位选和段选信号的控制
    always @(*) begin
        case (scan_sel)
            2'd0: begin
                dig0_3 = 4'b1110; // 选择第0位（最低位），低电平有效
                seg0_7 = seg_decoder(seconds % 10);
            end
            2'd1: begin
                dig0_3 = 4'b1101; // 选择第1位
                seg0_7 = seg_decoder(seconds / 10);
            end
            2'd2: begin
                dig0_3 = 4'b1011; // 选择第2位
                seg0_7 = seg_decoder(minutes % 10);
            end
            2'd3: begin
                dig0_3 = 4'b0111; // 选择第3位（最高位）
                seg0_7 = seg_decoder(minutes / 10);
            end
            default: begin
                dig0_3 = 4'b1111; // 所有位都不选中
                seg0_7 = 8'b1111_1111; // 段选信号全部拉高
            end
        endcase
    end

endmodule
