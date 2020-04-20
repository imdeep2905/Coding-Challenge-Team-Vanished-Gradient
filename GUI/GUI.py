from tkinter import Tk, Label, LabelFrame, PhotoImage, Button, Checkbutton, Entry, IntVar, StringVar, END, messagebox, OptionMenu
import os 
os.chdir("Src\\")
class MainApp:
    def __init__(self):
        self.root = Tk()
        self.root.title("KCLP Solution - Submitted by Team Vanished Gradient (Deep Raval, Jaymin Suhagiya)")
        self.root.tk.call('wm', 'iconphoto', self.root._w, PhotoImage(file='../Images/icon.png'))
        #self.root.geometry('360x100')
        self.root.resizable(0,0)
        self.switch_details = []
        
        self.details_lf = LabelFrame(self.root, text = " 1. Enter Rack & Switch Details: ")
        self.details_lf.grid(row = 0, columnspan = 10, sticky='W', padx=5, pady=5, ipadx=5, ipady=5)
        
        self.hyperparam_lf = LabelFrame(self.root, text = "2. Hyperparameteres:")
        self.hyperparam_lf.grid(row = 1, column = 0, columnspan = 5, sticky='W', padx=5, pady=5, ipadx=5, ipady=5)
        
        self.solve_lf= LabelFrame(self.root, text = "3. Execute and Stats:")
        self.solve_lf.grid(row = 1, column = 5, columnspan = 5, sticky='W', padx=5, pady=5, ipadx=5, ipady=5)
        
        Label(self.details_lf, text = "Rack length :").grid(row = 0, column = 0, sticky = 'E', padx = 5, pady = 2)
        self.rack_length = Entry(self.details_lf, width = 15)
        self.rack_length.grid(row = 0, column = 1, sticky = 'E', padx = 5, pady = 2)
        
        Label(self.details_lf, text = "Rack breadth :").grid(row = 0, column = 2, sticky = 'E', padx = 5, pady = 2)
        self.rack_breadth = Entry(self.details_lf, width = 15)
        self.rack_breadth.grid(row = 0, column = 3, sticky = 'E', padx = 5, pady = 2)
        
        Label(self.details_lf, text = "Rack height :").grid(row = 0, column = 4, sticky = 'E', padx = 5, pady = 2)
        self.rack_height = Entry(self.details_lf, width = 15)
        self.rack_height.grid(row = 0, column = 5, sticky = 'E', padx = 5, pady = 2)
        
        Label(self.details_lf, text = "Switch 1 (l, b, h, value, instances):").grid(row = 1, column = 0, sticky = 'E', padx = 5, pady = 2) 
        self.s1_l = Entry(self.details_lf, width = 15)
        self.s1_l.grid(row = 1, column = 1, sticky = 'E', padx = 5, pady = 2)
        self.s1_b = Entry(self.details_lf, width = 15)
        self.s1_b.grid(row = 1, column = 2, sticky = 'E', padx = 5, pady = 2)
        self.s1_h = Entry(self.details_lf, width = 15)
        self.s1_h.grid(row = 1, column = 3, sticky = 'E', padx = 5, pady = 2)
        self.s1_v = Entry(self.details_lf, width = 15)
        self.s1_v.grid(row = 1, column = 4, sticky = 'E', padx = 5, pady = 2)        
        self.s1_i = Entry(self.details_lf, width = 15)
        self.s1_i.grid(row = 1, column = 5, sticky = 'E', padx = 5, pady = 2)
        
        Label(self.details_lf, text = "Switch 2 (l, b, h, value, instances):").grid(row = 2, column = 0, sticky = 'E', padx = 5, pady = 2) 
        self.s2_l = Entry(self.details_lf, width = 15)
        self.s2_l.grid(row = 2, column = 1, sticky = 'E', padx = 5, pady = 2)
        self.s2_b = Entry(self.details_lf, width = 15)
        self.s2_b.grid(row = 2, column = 2, sticky = 'E', padx = 5, pady = 2)
        self.s2_h = Entry(self.details_lf, width = 15)
        self.s2_h.grid(row = 2, column = 3, sticky = 'E', padx = 5, pady = 2)
        self.s2_v = Entry(self.details_lf, width = 15)
        self.s2_v.grid(row = 2, column = 4, sticky = 'E', padx = 5, pady = 2)        
        self.s2_i = Entry(self.details_lf, width = 15)
        self.s2_i.grid(row = 2, column = 5, sticky = 'E', padx = 5, pady = 2)
        
        Label(self.details_lf, text = "Switch 3 (l, b, h, value, instances):").grid(row = 3, column = 0, sticky = 'E', padx = 5, pady = 2) 
        self.s3_l = Entry(self.details_lf, width = 15)
        self.s3_l.grid(row = 3, column = 1, sticky = 'E', padx = 5, pady = 2)
        self.s3_b = Entry(self.details_lf, width = 15)
        self.s3_b.grid(row = 3, column = 2, sticky = 'E', padx = 5, pady = 2)
        self.s3_h = Entry(self.details_lf, width = 15)
        self.s3_h.grid(row = 3, column = 3, sticky = 'E', padx = 5, pady = 2)
        self.s3_v = Entry(self.details_lf, width = 15)
        self.s3_v.grid(row = 3, column = 4, sticky = 'E', padx = 5, pady = 2)        
        self.s3_i = Entry(self.details_lf, width = 15)
        self.s3_i.grid(row = 3, column = 5, sticky = 'E', padx = 5, pady = 2)

        Label(self.details_lf, text = "Switch 4 (l, b, h, value, instances):").grid(row = 4, column = 0, sticky = 'E', padx = 5, pady = 2) 
        self.s4_l = Entry(self.details_lf, width = 15)
        self.s4_l.grid(row = 4, column = 1, sticky = 'E', padx = 5, pady = 2)
        self.s4_b = Entry(self.details_lf, width = 15)
        self.s4_b.grid(row = 4, column = 2, sticky = 'E', padx = 5, pady = 2)
        self.s4_h = Entry(self.details_lf, width = 15)
        self.s4_h.grid(row = 4, column = 3, sticky = 'E', padx = 5, pady = 2)
        self.s4_v = Entry(self.details_lf, width = 15)
        self.s4_v.grid(row = 4, column = 4, sticky = 'E', padx = 5, pady = 2)        
        self.s4_i = Entry(self.details_lf, width = 15)
        self.s4_i.grid(row = 4, column = 5, sticky = 'E', padx = 5, pady = 2)

        Label(self.details_lf, text = "Switch 5 (l, b, h, value, instances):").grid(row = 5, column = 0, sticky = 'E', padx = 5, pady = 2) 
        self.s5_l = Entry(self.details_lf, width = 15)
        self.s5_l.grid(row = 5, column = 1, sticky = 'E', padx = 5, pady = 2)
        self.s5_b = Entry(self.details_lf, width = 15)
        self.s5_b.grid(row = 5, column = 2, sticky = 'E', padx = 5, pady = 2)
        self.s5_h = Entry(self.details_lf, width = 15)
        self.s5_h.grid(row = 5, column = 3, sticky = 'E', padx = 5, pady = 2)
        self.s5_v = Entry(self.details_lf, width = 15)
        self.s5_v.grid(row = 5, column = 4, sticky = 'E', padx = 5, pady = 2)        
        self.s5_i = Entry(self.details_lf, width = 15)
        self.s5_i.grid(row = 5, column = 5, sticky = 'E', padx = 5, pady = 2)
        
        self.strat_option_var = StringVar(self.root)
        choices = { 'Strategy 2','Strategy 3','Strategy 1'}
        self.strat_option_var.set('Strategy 3') 
        self.strat_option = OptionMenu(self.hyperparam_lf, self.strat_option_var, *choices)
        Label(self.hyperparam_lf, text="Choose a Strategy: ").grid(row = 0, column = 0)
        self.strat_option.grid(row = 0, column = 1)
        
        self.orientation_allowed_var = IntVar()
        self.orientation_allowed = Checkbutton(self.hyperparam_lf,variable = self.orientation_allowed_var, text="Orientation allowed", onvalue = 1, offvalue = 0)
        self.orientation_allowed.grid(row = 0, column=2, pady = 2, sticky = 'WE')
        self.orientation_allowed.select()
                
        self.pairing_allowed_var = IntVar()
        self.pairing_allowed = Checkbutton(self.hyperparam_lf,variable = self.pairing_allowed_var, text="Pairing allowed", onvalue = 1, offvalue = 0)
        self.pairing_allowed.grid(row = 0, column=3, pady = 2, sticky = 'WE')
        self.pairing_allowed.select()

        Label(self.hyperparam_lf, text = "Strategy 1: width,depth: Value||Volume").grid(row = 1, column = 0, columnspan = 3, sticky='W', padx=5, pady=5, ipadx=5, ipady=5)
        Label(self.hyperparam_lf, text = "Strategy 2: width,depth: Value/Volume").grid(row = 2, column = 0, columnspan = 3, sticky='W', padx=5, pady=5, ipadx=5, ipady=5)
        Label(self.hyperparam_lf, text = "Strategy 3: width:Value||Volume, depth:Value/Volume (Most Preferred)").grid(row = 3, column = 0, columnspan = 3, sticky='W', padx=5, pady=0, ipadx=5, ipady=4)
        
        self.exec_time_lbl = Label(self.solve_lf, text = "Execution Completed in: - Seconds")
        self.exec_time_lbl.grid(row = 0, column = 0, columnspan = 5 , pady = 2, sticky = 'W')
        
        self.rs_lbl = Label(self.solve_lf, text = "Remaining Switches:- ")
        self.rs_lbl.grid(row = 1, column = 0, columnspan = 5, sticky='W', padx=5, pady=5)
        
        self.val_gain_lbl = Label(self.solve_lf, text = "Total Value gained: - ")
        self.val_gain_lbl.grid(row = 2, column = 0, columnspan = 5, sticky='W', padx=5, pady=5)
        
        self.vol_pack_lbl = Label(self.solve_lf, text = "% of total volume packed: - %")
        self.vol_pack_lbl.grid(row = 3, column = 0, columnspan = 5, sticky='W', padx=5, pady=5)
        
        self.reset_btn = Button(self.solve_lf, text = "Reset", bg = "lightblue", command = self.reset)
        self.reset_btn.grid(row = 4, column = 2, sticky='W', padx=5, pady=0, ipadx=5, ipady=0)        
        self.solve_btn = Button(self.solve_lf, text = "Solve", bg = "lightblue", command = self.solve)
        self.solve_btn.grid(row = 4, column = 3, sticky='W', padx=5, pady=0, ipadx=5, ipady=0)
        self.vis_btn = Button(self.solve_lf, text = "Visualize", bg = "lightblue", command = self.visualize)
        self.vis_btn.grid(row = 4, column = 4, sticky='W', padx=5, pady=0, ipadx=5, ipady=0)

        
    def run(self):
        self.root.mainloop()
        
    def reset(self):
        self.rack_length.delete(0, END)
        self.rack_height.delete(0, END)
        self.rack_breadth.delete(0, END)
        
        self.s1_b.delete(0, END)
        self.s1_h.delete(0, END)
        self.s1_i.delete(0, END)
        self.s1_l.delete(0, END)
        self.s1_v.delete(0, END)
        
        self.s2_b.delete(0, END)
        self.s2_h.delete(0, END)
        self.s2_i.delete(0, END)
        self.s2_l.delete(0, END)
        self.s2_v.delete(0, END)
        
        self.s3_b.delete(0, END)
        self.s3_h.delete(0, END)
        self.s3_i.delete(0, END)
        self.s3_l.delete(0, END)
        self.s3_v.delete(0, END)
        
        self.s4_b.delete(0, END)
        self.s4_h.delete(0, END)
        self.s4_i.delete(0, END)
        self.s4_l.delete(0, END)
        self.s4_v.delete(0, END)
        
        self.s5_b.delete(0, END)
        self.s5_h.delete(0, END)
        self.s5_i.delete(0, END)
        self.s5_l.delete(0, END)
        self.s5_v.delete(0, END)
        
        self.exec_time_lbl["text"] = "Execution Completed in: - Seconds"
        self.rs_lbl["text"] = "Remaining Switches:- "
        self.val_gain_lbl["text"] = "Total Value gained: - "
        self.vol_pack_lbl["text"] = "% of total volume packed: - %"
        
    def solve(self):
        try:
            self.switch_details.clear()
            self.switch_details.append((int(self.rack_length.get()), int(self.rack_breadth.get()), int(self.rack_height.get())))
            self.switch_details.append((int(self.s1_l.get()), int(self.s1_b.get()), int(self.s1_h.get()), int(self.s1_v.get()), int(self.s1_i.get())))
            self.switch_details.append((int(self.s2_l.get()), int(self.s2_b.get()), int(self.s2_h.get()), int(self.s2_v.get()), int(self.s2_i.get())))
            self.switch_details.append((int(self.s3_l.get()), int(self.s3_b.get()), int(self.s3_h.get()), int(self.s3_v.get()), int(self.s3_i.get())))
            self.switch_details.append((int(self.s4_l.get()), int(self.s4_b.get()), int(self.s4_h.get()), int(self.s4_v.get()), int(self.s4_i.get())))
            self.switch_details.append((int(self.s5_l.get()), int(self.s5_b.get()), int(self.s5_h.get()), int(self.s5_v.get()), int(self.s5_i.get())))
        except ValueError:
            messagebox.showerror("An Error Occured", "Please fill all input fields with number !")
            return
        with open("input.txt",'w') as f:
            for i in self.switch_details:
                for j in i:
                    f.write(' '+str(j))
        import subprocess
        o = bool(self.orientation_allowed_var.get())
        p = bool(self.pairing_allowed_var.get())
        s = self.strat_option_var.get()
        if o:
            if p:
                if s == "Strategy 1":
                    subprocess.check_call("Solution_Orientation_and_Pairing_Allowed_S1.exe")
                elif s == "Strategy 2":
                    subprocess.check_call("Solution_Orientation_and_Pairing_Allowed_S2.exe")
                elif s == "Strategy 3":                    
                    subprocess.check_call("Solution_Orientation_and_Pairing_Allowed_S3.exe")
            else:
                if s == "Strategy 1":
                    subprocess.check_call("Solution_Orientation_Allowed_S1.exe")
                elif s == "Strategy 2":
                    subprocess.check_call("Solution_Orientation_Allowed_S2.exe")
                elif s == "Strategy 3":                    
                    subprocess.check_call("Solution_Orientation_Allowed_S3.exe")                
        else:
            if p:
                if s == "Strategy 1":
                    subprocess.check_call("Solution_Pairing_Allowed_S1.exe")
                elif s == "Strategy 2":
                    subprocess.check_call("Solution_Pairing_Allowed_S2.exe")
                elif s == "Strategy 3":                    
                    subprocess.check_call("Solution_Pairing_Allowed_S3.exe")
            else:
                if s == "Strategy 1":
                    subprocess.check_call("Solution_S1.exe")
                elif s == "Strategy 2":
                    subprocess.check_call("Solution_S2.exe")
                elif s == "Strategy 3":                    
                    subprocess.check_call("Solution_S3.exe")                
                
        with open("forgui.txt") as f:
            data = f.readlines()
        self.exec_time_lbl["text"] = data[0]
        self.rs_lbl["text"] = data[1]
        self.val_gain_lbl["text"] = data[2]
        self.vol_pack_lbl["text"] = data[3]
        self.visualize()
    
    def visualize(self):
        if self.exec_time_lbl["text"] == "Execution Completed in: - Seconds":
            messagebox.showerror("An error occured !", "Solve problem before visulaizing it !")
            return 
        import matplotlib.pyplot as plt

        #5 different colors for 5 different switches (RGBA)
        colors = [(1, 0.1, 0.1, 1), (0.1, 1, 0.1, 1), (0.1, 181/255., 204/255., 1), (1, 0.5, 0.1, 1), (0.23, 0.23, 0.23, 1)]

        #Opening "output.txt" which have info about switches position and their orientation
        with open("output.txt",'r') as f:
            data = f.readlines()

        
        rz, ry, rx = [int(x) for x in data[0].split()]
        data.pop(0)
        fig = plt.figure()
        ax = fig.gca(projection='3d')
        #Making Boundary to fill smooth orientations
        ax.bar3d(0, 0, 0, max(ry,rz,rx), max(ry,rz,rx), max(ry,rz,rx), color = (0, 0, 0, 0), shade = False)
        #Making legend
        type_0 = plt.Rectangle((0, 0), 1, 1, fc = colors[0])
        type_1 = plt.Rectangle((0, 0), 1, 1, fc = colors[1])
        type_2 = plt.Rectangle((0, 0), 1, 1, fc = colors[2])
        type_3 = plt.Rectangle((0, 0), 1, 1, fc = colors[3])
        type_4 = plt.Rectangle((0, 0), 1, 1, fc = colors[4])
        ax.legend([type_0, type_1, type_2, type_3, type_4],['Type 0', 'Type 1', 'Type 2', 'Type 3', 'Type 4'])
        #Creating transparant rack  
        ax.bar3d(0, 0, 0, rx, ry, rz, color = (0, 0, 0, 0.1), shade = False)
        for line in data:
            #Creating switch with appropiate colors
            t, dz, dy, dx, x, y, z = [int(x) for x in line.split()]
            ax.bar3d(x, y, z, dx, dy, dz, color = colors[t], edgecolor = (0, 0, 0, 1), shade = False) 
            
        ax.set_title('Visualization of placed switches')
        plt.show()
        
if __name__ == "__main__":
    MainApp().run()